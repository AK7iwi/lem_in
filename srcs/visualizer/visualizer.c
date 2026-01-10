#include "lem_in.h"

bool	visualizer(t_data *data)
{
	SDL_Window	    *window;
	SDL_Renderer    *renderer;

	if (init_render(data, &window, &renderer))
		return (close_render(window, renderer), 1); //maybe just return (1)
	set_render_params(&data->norm, data->map->nb_rooms);
	if (render(renderer, data))
		return (close_render(window, renderer), 1);
	return (close_render(window, renderer), 0);
}
