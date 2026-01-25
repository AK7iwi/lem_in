#include "lem_in.h"

bool	parse_cmd_and_cmt(t_data *data, int fd, char *line)
{
	bool	is_start, is_end;

	return (validate_cmd_and_cmt(data, line, &is_start, &is_end)
		 || create_cmd(data, fd, is_start, is_end));
}
