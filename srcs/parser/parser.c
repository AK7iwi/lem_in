#include "lem_in.h"

bool	parser(t_data	*data, int	fd, int	argc)
{
	if (!has_no_arg(argc))
		return (data->err.parsing_errors |= E_ARGC, EXIT_FAILURE);
	if (parse_data(data, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
