#include "lem_in.h"

static	bool	parse_line(t_data *data, int fd, char *line)
{
	if (is_empty_line(line))
		return (data->err.parsing_errors |= E_EMPTY_LINE, 1);

	return (parse_ants(data, line)
			&& parse_cmd_and_cmt(data, fd, line)
			&& parse_room(data, line, false, false)
			&& parse_link(data, line));
}

bool	parse_map(t_data *data, int fd)
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
			data->err.line_error += i + data->map->nb_valid_cmds + 1;  
			return (free(line), 1);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}
