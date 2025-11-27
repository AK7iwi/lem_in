#include "lem_in.h"

int	main(int	argc, char	**argv)
{
	t_data	data;

	init(&data, argv);
	if (parser(&data, STDIN_FILENO, argc))
	{
		errors_displayer(data.err);
		return (free_data(&data), EXIT_FAILURE);
	}
	print_general_infos(&data);
	// print_map(&data);
	return (free_data(&data), EXIT_SUCCESS);
}
