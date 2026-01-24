#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init(&data, argv) || parser(&data, STDIN_FILENO, argc))
	{
		display_errors(data.err);
		free_data(&data);
		return (EXIT_FAILURE);
	}
	display_infos(&data);
	if (visualizer(&data))
	{
		display_errors(data.err);
		free_data(&data);
		return (EXIT_FAILURE);
	}

	free_data(&data);
	return (EXIT_SUCCESS);
}
