#include "lem_in.h"

bool	validate_cmd_and_cmt(t_data	*data, char	*line, bool *is_start, bool *is_end)
{
	(*is_start) = false;
	(*is_end) = false;

	if (validate_cmd_and_cmt_format(line, is_start, is_end))
		return (1);
	if (validate_cmd_and_cmt_value(data, *is_start, *is_end))
		return (1);

	return (0);
}
