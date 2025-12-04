#include "lem_in.h"

bool	parse_line(t_data	*data, int	fd, char	*line)
{
	if (is_empty_line(line))
		return (EXIT_FAILURE);
	if (!parse_ants(data, line)) 
		return (EXIT_SUCCESS);
	if (!parse_command_and_comment(data, fd, line)
		|| !parse_room(data, line, false, false)
		|| !parse_link(data, line))
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
