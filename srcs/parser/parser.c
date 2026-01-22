#include "lem_in.h"

bool	parser(t_data *data, int fd, int argc)
{
	if (!has_no_arg(argc))
		return (data->err.parsing_errors |= E_ARGC, 1);

	return (parse_data(data, fd));
}
