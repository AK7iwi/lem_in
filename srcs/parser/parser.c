#include "lem_in.h"

static	inline	bool	has_more_than_one_arg(t_err *err, int argc)
{
	return ((argc != 1) && (err->parsing_errors |= E_ARGC));
}

bool	parser(t_data	*data, int	fd, int	argc)
{
	return (has_more_than_one_arg(&data->err, argc) || parse_data(data, fd));
}
