#include "lem_in.h"

static	inline	void	init_normalize(t_data *data)
{
	data->norm.window_width = WINDOW_WIDTH;
	data->norm.window_height = WINDOW_HEIGHT;
	data->norm.min_x = MAX_COORDINATE;
	data->norm.max_x = 0.0f;
	data->norm.min_y = MAX_COORDINATE;
	data->norm.max_y = 0.0f;
	data->norm.scale = 0.0f;
	data->norm.offset_x = 0.0f;
	data->norm.offset_y = 0.0f;
	data->norm.radius = 0.0f;
	data->norm.zoom = 1.0f;
	data->norm.pan_x = 0.0f;
	data->norm.pan_y = 0.0f;
}

static	bool	init_map(t_data	*data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (data->err.gen_errors |= E_MEMORY, 1);
	data->map->nb_rooms = 0;
	data->map->capacity = 0;
	data->map->nb_links = 0;
	data->map->nb_valid_cmds = 0;
	data->map->rooms = NULL;
	data->map->start_room = NULL;
	data->map->end_room = NULL;

	return (0);
}

static	inline	void	init_ants(t_data *data)
{
	data->nb_ants = 0;
	data->ant = NULL;
}

static	inline	void	init_errors(t_data *data)
{
	data->err.line_error = 0;
	data->err.gen_errors = 0;
	data->err.parsing_errors = 0;
	data->err.visu_errors = 0;
}

bool	init(t_data *data, char **argv)
{
	(void)argv;
	init_errors(data);
	init_normalize(data);
	init_ants(data);
	return (init_map(data));
}
