#include "lem_in.h"

bool	visualizer(t_data *data)
{
	SDL_Window	    *window;
	SDL_Renderer    *renderer;

	if (init_render(data, &window, &renderer))
		return (1);
	set_render_params(&data->norm, data->map->nb_rooms);
	render(renderer, data);
	close_render(window, renderer);

	return (0);
}
