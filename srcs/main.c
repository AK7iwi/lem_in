#include "lem_in.h"

int	main(int	argc, char	**argv)
{
	t_data	data;

	init(&data, argv);
	if (parser(&data, STDIN_FILENO, argc))
		return (errors_displayer(data.err), EXIT_FAILURE);
	print_general_infos(data);
	return (EXIT_SUCCESS);
}
