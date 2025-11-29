#include "lem_in.h"

static	bool	is_valid_map(t_data	*data)
{
	if (!data->map->start_room)
		return (false); // start error
	if (!data->map->end_room)
		return (false); //end error
	if (data->map->nb_links < data->map->nb_rooms - 1)
		return (false); // Not enough links error 
	if (!has_path(data->map)) /* BFS algo */
		return (false); // no path error

	return (true);
}

bool	parse_data(t_data *data, int fd)
{
	char	*line;
	uint8_t	empty_line_result;
	size_t	i = 0;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE); //empty file message error
	while (line)
	{
		empty_line_result = parse_empty_line(data, fd, line);
		if (empty_line_result == 1) /* Empty lines at end of file */
		{
			free(line);
			break;
		}
		else if (empty_line_result == 2) /* Empty line in the middle of the file */
			return (free(line), EXIT_FAILURE);
		else if (parse_line(data, fd, line, i))
			return (free(line), EXIT_FAILURE);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (!is_valid_map(data))
		return (EXIT_FAILURE); // map error
	return (EXIT_SUCCESS);
}
