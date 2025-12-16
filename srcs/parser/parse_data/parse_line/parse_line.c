#include "lem_in.h"

bool	parse_line(t_data *data, int fd, char *line)
{
	if (is_empty_line(line))
		return (data->err.parsing_errors |= E_EMPTY_LINE, 1);

	return (parse_ants(data, line)
			&& parse_cmd_and_cmt(data, fd, line)
			&& parse_room(data, line, false, false)
			&& parse_link(data, line));
}
