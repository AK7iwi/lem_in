#include "lem_in.h"

bool	parse_link(char *line)
{
	size_t		i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_name(line, &i)) //existing room
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (line[i] != '-')
		return (EXIT_FAILURE);
	i++;
	skip_space(line, &i);
	if (!is_valid_name(line, &i))
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);

	return(EXIT_SUCCESS);
}

bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end)
{
	size_t	i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_name(line, &i)) /* Room's name */
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_valid_number(line, &i)) /* coord_x */
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_valid_number(line, &i)) /* coord_y */
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);
	fill_room(data, line, is_start, is_end);
	return (EXIT_SUCCESS);
}

bool	parse_comment(t_data *data, int	fd, char	*line)
{
	size_t			i;
	static	bool	start_flag = false;
	static	bool	end_flag = false;
	char			*next_line;

	i = 0;
	skip_space(line, &i);
	if (line[i] == '#') 
	{
		if (line[i + 1] == '#')
		{
			i += 2;
			skip_space(line, &i);
			if (is_start_room(line, &i))
			{
				if (start_flag)
					return (EXIT_FAILURE);
				start_flag = true;
			}
			else if (is_end_room(line, &i))
			{
				if (end_flag)
					return (EXIT_FAILURE);
				end_flag = true;
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

	free(line);
	next_line = get_next_line(fd);
	if (!next_line || parse_room(data, next_line, nb_start, nb_end))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

bool	parse_nb_ants_line(t_data *data, char	*line)
{
	size_t	i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	fill_nb_ants(data, line);
	return (EXIT_SUCCESS);
}
