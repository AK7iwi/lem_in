#include "lem_in.h"

bool	parse_line(t_data	*data, int	fd, char	*line)
{
	if (is_empty_line(line))
		return (1);
	if (!parse_ants(data, line) 
		|| !parse_cmd_and_cmt(data, fd, line)
		|| !parse_room(data, line, false, false)
		|| !parse_link(data, line))
		return (0);

	return (1);
}
