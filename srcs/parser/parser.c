#include "lem_in.h"

bool	parser(t_data *data, int fd, int argc)
{
	if (!has_no_arg(argc))
	{
		data->err.parsing_errors |= E_ARGC;
		return (1);
	}

	return (parse_data(data, fd));
}
