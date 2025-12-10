#include "lem_in.h"

static	bool	is_valid_map(t_data *data)
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

static	bool	parse_map(t_data *data, int fd)
{
	char	*line;
	size_t	i = 0;

	line = get_next_line(fd);
	if (!line)
		return (data->err.parsing_errors |= E_EMPTY_FILE, 1);
	while (line)
	{
		if (parse_line(data, fd, line))
		{
			data->err.line_error += (i + data->map->nb_valid_cmds + 1);  
			return (free(line), 1);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}

bool	parse_data(t_data *data, int fd)
{
	if (parse_map(data, fd))
		return (1); // bad value error
	if (!is_valid_map(data))
		return (1); // missing info error
	set_start_room(data);

	return (0);
}
