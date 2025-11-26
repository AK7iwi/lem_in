#include "lem_in.h"

int	main(int	argc, char	**argv)
{
	t_data	data;

	init(&data, argv);
	if (parser(&data, STDIN_FILENO, argc))
	{
		errors_displayer(data.err);
		free_data(&data);
		return (EXIT_FAILURE);
	}
	print_general_infos(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
