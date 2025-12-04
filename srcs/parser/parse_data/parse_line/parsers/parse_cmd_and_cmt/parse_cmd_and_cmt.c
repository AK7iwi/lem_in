#include "lem_in.h"

static	bool	handle_valid_cmd(t_data	*data, int fd, bool is_start, bool	is_end)
{
	char	*next_line;

	if (!is_start && !is_end)
		return (0); /* Unknow command or comment */
	next_line = get_next_line(fd);
	if (!next_line || parse_room(data, next_line, is_start, is_end))
	{
		if (next_line)
			free(next_line);
		return (1);
	}
	free(next_line);

	return (0);
}

bool	parse_cmd_and_cmt(t_data *data, int fd, char *line)
{
	bool	is_start, is_end;

	if (validate_cmd_and_cmt(data, line, &is_start, &is_end))
		return (1);
	if (handle_valid_cmd(data, fd, is_start, is_end))
		return (1); //bad room after valid cmd
	return (0);
}
