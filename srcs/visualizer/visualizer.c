#include "lem_in.h"

bool	visualizer(t_data *data)
{
	SDL_Window	    *window = NULL;
	SDL_Renderer    *renderer = NULL;
	SDL_Texture		*map_cache = NULL;

	if (init_render(data, &window, &renderer, &map_cache))
		return (close_render(window, renderer, map_cache), 1);
	set_params(&data->norm, data->map->nb_rooms);
	if (render(data, renderer, map_cache))
		return (close_render(window, renderer, map_cache), 1);

	return (close_render(window, renderer, map_cache), 0);
}
