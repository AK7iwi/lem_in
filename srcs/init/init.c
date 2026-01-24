#include "lem_in.h"

static	inline	void	init_normalize(t_normalize *norm)
{
	norm->window_width = 0;
	norm->window_height = 0;
	norm->min_x = MAX_COORDINATE;
	norm->max_x = 0.0f;
	norm->min_y = MAX_COORDINATE;
	norm->max_y = 0.0f;
	norm->scale = 0.0f;
	norm->offset_x = 0.0f;
	norm->offset_y = 0.0f;
	norm->radius = 0.0f;
	norm->zoom = 1.0f;
	norm->pan_x = 0.0f;
	norm->pan_y = 0.0f;
}

static	inline	void	init_ants(t_data *data)
{
	data->nb_ants = 0;
	data->ant = NULL;
}

static	bool	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		data->err.gen_errors |= E_MEMORY;
		return (1);
	}
	data->map->nb_rooms = 0;
	data->map->capacity = 0;
	data->map->nb_links = 0;
	data->map->nb_valid_cmds = 0;
	data->map->rooms = NULL;
	data->map->start_room = NULL;
	data->map->end_room = NULL;

	return (0);
}

static	inline	void	init_errors(t_err *err)
{
	err->line_error = 0;
	err->gen_errors = 0;
	err->parsing_errors = 0;
	err->visu_errors = 0;
}

bool	init(t_data *data, char **argv)
{
	(void)argv;

	init_errors(&data->err);
	if (init_map(data))
		return (1);
	init_ants(data);
	init_normalize(&data->norm);

	return (0);
}
