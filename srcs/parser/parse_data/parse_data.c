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

static	bool	parse_map(t_data	*data, int	fd)
{
	char	*line;
	size_t	i = 0;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE); //empty file message error
	while (line)
	{
		if (parse_line(data, fd, line))
			return (free(line), EXIT_FAILURE); //return i for line error 
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

bool	parse_data(t_data	*data, int	fd)
{
	if (parse_map(data, fd))
		return (EXIT_FAILURE); // bad value error
	if (!is_valid_map(data))
		return (EXIT_FAILURE); // missing info error
	return (EXIT_SUCCESS);
}
