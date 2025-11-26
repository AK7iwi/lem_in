#include "lem_in.h"

bool	parse_link(t_data *data, char *line)
{
	size_t		i = 0;
	t_room		*room1, *room2;

	skip_space(line, &i);
	room1 = is_existing_room(data, line, &i);
	if (!room1)
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (line[i] != '-')
		return (EXIT_FAILURE);
	i++;
	room2 = is_existing_room(data, line, &i);
	if (!room2)
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);
	if (init_link(room1, room2))
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end)
{
	size_t	i = 0;
	size_t	name_start, name_end;
	size_t	x_start, x_end;
	size_t	y_start, y_end;

	skip_space(line, &i);
	name_start = i;
	if (!is_valid_name(data, line, &i)) /* Room's name */
		return (EXIT_FAILURE);
	name_end = i;
	skip_space(line, &i);
	x_start = i;
	if (!is_valid_number(line, &i)) /* coord_x */
		return (EXIT_FAILURE);
	x_end = i;
	skip_space(line, &i);
	y_start = i;
	if (!is_valid_number(line, &i)) /* coord_y */
		return (EXIT_FAILURE);
	y_end = i;
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);
	if (init_room(data, line, name_start, name_end, x_start, x_end, y_start, y_end, is_start, is_end))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	parse_comment(t_data *data, int	fd, char	*line)
{
	size_t			i = 0;
	static	bool	start_flag = false, end_flag = false;
	bool 			is_start, is_end;
	char			*next_line;

	skip_space(line, &i);
	if (line[i] == '#') 
	{
		if (line[i + 1] == '#')
		{
			i += 2;
			skip_space(line, &i);
			is_start = is_start_room(line, i);
			is_end = is_end_room(line, i);
			if (is_start)
			{
				if (start_flag)
					return (EXIT_FAILURE);
				start_flag = true;
				i += 5;
			}
			else if (is_end)
			{
				if (end_flag)
					return (EXIT_FAILURE);
				end_flag = true;
				i += 3;
			}
			else
				return (EXIT_SUCCESS);
		}
		else
			return (EXIT_SUCCESS);
	}
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);

	next_line = get_next_line(fd);
	if (!next_line || parse_room(data, next_line, is_start, is_end))
	{
		if (next_line)
			free(next_line);
		return (EXIT_FAILURE);
	}
	free(next_line);
	return (EXIT_SUCCESS);
}

bool	parse_nb_ants_line(t_data *data, char	*line)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	init_nb_ants(data, line);
	return (EXIT_SUCCESS);
}
