#include "lem_in.h"

bool	visualizer(t_data *data)
{
	SDL_Window	    *window = NULL;
	SDL_Renderer    *renderer = NULL;

	if (init_render(data, &window, &renderer))
		return (close_render(window, renderer), 1);
	set_render_params(&data->norm, data->map->nb_rooms);
	if (render(renderer, data))
		return (close_render(window, renderer), 1);

	return (close_render(window, renderer), 0);
}
