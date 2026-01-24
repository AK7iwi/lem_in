#include "lem_in.h"

bool	create_cmd(t_data *data, int fd, bool is_start, bool is_end)
{
	char	*next_line;

	/* Unknow command or comment */
	if (!is_start && !is_end)
		return (0);

	data->map->nb_valid_cmds++;
	next_line = get_next_line(fd);
	if (!next_line || parse_room(data, next_line, is_start, is_end)) 
	{
		if (next_line)
			free(next_line);
		if (is_start)
			data->err.parsing_errors |= E_START;
		else if (is_end)
			data->err.parsing_errors |= E_END;
		return (1);
	}
	free(next_line);

	return (0);
}
