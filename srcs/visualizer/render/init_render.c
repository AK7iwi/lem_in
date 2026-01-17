#include "lem_in.h"

static	bool create_map_cache(t_data *data, SDL_Renderer *renderer, SDL_Texture **map_cache)
{
	*map_cache = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_TARGET, data->norm.window_width, data->norm.window_height);

	return (!*map_cache);
}

static	bool set_renderer(SDL_Renderer *renderer)
{
	return (!SDL_SetRenderVSync(renderer, 1));
}

static	bool create_window_and_renderer(t_data *data, SDL_Window **window, SDL_Renderer **renderer)
{
	return (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", data->norm.window_width, data->norm.window_height, SDL_WINDOW_RESIZABLE, window, renderer));
}

static	bool set_window_size(t_data *data)
{
	const SDL_DisplayMode	*display_mode;

	display_mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
	if (!display_mode)
		return (1);
	/* Use 90% of screen size */
	data->norm.window_width = (uint16_t)(display_mode->w * 0.9f);
	data->norm.window_height = (uint16_t)(display_mode->h * 0.9f);

	return (0);
}

static	bool init_SDL(void)
{
	return (!SDL_Init(SDL_INIT_VIDEO));
}

bool    init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **map_cache)
{
	return ((init_SDL()
	|| set_window_size(data)
	|| create_window_and_renderer(data, window, renderer)
	|| set_renderer(*renderer)
	|| create_map_cache(data, *renderer, map_cache)) ? (data->err.visu_errors |= E_VISU, 1) : 0);
}
