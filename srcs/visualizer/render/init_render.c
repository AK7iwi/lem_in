#include "lem_in.h"

static	bool	create_map_cache(t_normalize *norm, SDL_Renderer *renderer, SDL_Texture **map_cache)
{
	*map_cache = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_TARGET, norm->window_width, norm->window_height);

	return (!*map_cache);
}

static	inline	bool	set_renderer(SDL_Renderer *renderer)
{
	return (!SDL_SetRenderVSync(renderer, 1));
}

static	bool	create_window_and_renderer(t_normalize *norm, SDL_Window **window, SDL_Renderer **renderer)
{
	return (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", norm->window_width, norm->window_height, SDL_WINDOW_RESIZABLE, window, renderer));
}

static	bool	set_window_size(t_normalize *norm)
{
	const SDL_DisplayMode	*display_mode;

	display_mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
	if (!display_mode)
		return (1);
	/* Use 90% of screen size */
	norm->window_width = (uint16_t)(display_mode->w * 0.9f);
	norm->window_height = (uint16_t)(display_mode->h * 0.9f);

	return (0);
}

static	inline	bool	init_SDL(void)
{
	return (!SDL_Init(SDL_INIT_VIDEO));
}

bool    init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **map_cache)
{
	if (init_SDL()
	 || set_window_size(&data->norm)
	 || create_window_and_renderer(&data->norm, window, renderer)
	 || set_renderer(*renderer)
	 || create_map_cache(&data->norm, *renderer, map_cache))
	{
		data->err.visu_errors |= E_VISU;
		return (1);
	}

	return (0);
}
