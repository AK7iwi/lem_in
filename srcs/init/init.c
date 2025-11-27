#include "lem_in.h"

static	bool	init_map(t_data	*data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (EXIT_FAILURE); // memory error
	data->map->nb_rooms = 0;
	data->map->capacity = 0;
	data->map->nb_links = 0;
	data->map->rooms = NULL;
	data->map->start_room = NULL;
	data->map->end_room = NULL;
	return (EXIT_SUCCESS);
}

static	bool	init_data(t_data *data)
{
	data->ant = NULL;

	if (init_map(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	inline	void	init_errors(t_data *data)
{
	data->err.gen_errors = 0;
	data->err.parsing_errors = 0;
}

bool	init(t_data *data, char **argv)
{
	(void)argv;
	init_errors(data);
	if (init_data(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
