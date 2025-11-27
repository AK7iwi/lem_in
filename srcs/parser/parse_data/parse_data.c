#include "lem_in.h"

static	bool	parse_line(t_data *data, int	fd, char	*line, size_t	i)
{	
	if (i == 0 && !parse_nb_ants_line(data, line))
		return (EXIT_SUCCESS);
	if (!parse_command_and_comment(data, fd, line)
		|| !parse_room(data, line, false, false)
		|| !parse_link(data, line))
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}

static	uint8_t	parse_empty_line(t_data	*data, int	fd, char	*line)
{
	char	*next_line;

	if (is_last_char(line[0]))
	{
		next_line = get_next_line(fd);
		while (next_line && is_last_char(next_line[0]))
		{
			free(next_line);
			next_line = get_next_line(fd);
		}
		if (!next_line)
			return (1);
		free(next_line);
		return (data->err.parsing_errors |= E_EMPTY_LINE, 2);
	}
	return (0);
}

bool	parse_data(t_data *data, int fd)
{
	char	*line;
	uint8_t empty_line_result;
	size_t  i = 0;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE); //empty file message error
	while (line)
	{
		empty_line_result = parse_empty_line(data, fd, line);
		if (empty_line_result == 1)
		{
			free(line);
			break;
		}
		else if (empty_line_result == 2)
			return (free(line), EXIT_FAILURE);
		else if (parse_line(data, fd, line, i))
			return (free(line), EXIT_FAILURE);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	//fct to check that map is valid
	if (!data->map->start_room)
		return (EXIT_FAILURE); // start error
	if (!data->map->end_room)
		return (EXIT_FAILURE); //end error
	if (data->map->nb_links < data->map->nb_rooms - 1)
		return (EXIT_FAILURE); // Not enough links error 
	return (EXIT_SUCCESS);
}
