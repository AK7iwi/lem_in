#include "lem_in.h"

void	close_render(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *map_cache)
{
	if (map_cache)
		SDL_DestroyTexture(map_cache);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
}

static	bool	needs_cache_update(t_data *data)
{
	static float	last_zoom = 1.0f;
	static float	last_pan_x = 0.0f;
	static float	last_pan_y = 0.0f;

	if (data->norm.zoom != last_zoom || data->norm.pan_x != last_pan_x || data->norm.pan_y != last_pan_y)
	{
		last_zoom = data->norm.zoom;
		last_pan_x = data->norm.pan_x;
		last_pan_y = data->norm.pan_y;
		return (true);
	}

	return (false);
}

static	bool	render_to_cache(t_data *data, SDL_Renderer *renderer, SDL_Texture *map_cache)
{	
	if (!SDL_SetRenderTarget(renderer, map_cache))
		return (1);

	if (!SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
		|| !SDL_RenderClear(renderer)
		|| !SDL_SetRenderScale(renderer, data->norm.zoom, data->norm.zoom)
		|| draw_render(data, renderer))
	{
		SDL_SetRenderTarget(renderer, NULL);
		return (1);
	}

	if (!SDL_SetRenderTarget(renderer, NULL))
		return (1);

	return (0);
}

bool	render(t_data *data, SDL_Renderer *renderer, SDL_Texture *map_cache)
{
	bool			running = true;

	if (render_to_cache(data, renderer, map_cache))
		return (data->err.visu_errors |= E_VISU, 1);

	while (running)
	{
		if (render_event(data))
			running = false;
		if (needs_cache_update(data))
			if (render_to_cache(data, renderer, map_cache))
				return (data->err.visu_errors |= E_VISU, 1);

		if (!SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
			|| !SDL_RenderClear(renderer)
			|| !SDL_RenderTexture(renderer, map_cache, NULL, NULL)
			|| !SDL_RenderPresent(renderer))
			return (data->err.visu_errors |= E_VISU, 1);
	}
	
	return (0);
}

bool    init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **map_cache)
{
	const SDL_DisplayMode	*display_mode;

	if (!SDL_Init(SDL_INIT_VIDEO))
		return (data->err.visu_errors |= E_VISU, 1);

	display_mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
	if (!display_mode)
		return (data->err.visu_errors |= E_VISU, 1);
	data->norm.window_width = (uint16_t)(display_mode->w * 0.9f); /* Use 90% of screen size */
	data->norm.window_height = (uint16_t)(display_mode->h * 0.9f);

	if (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", data->norm.window_width, data->norm.window_height, SDL_WINDOW_RESIZABLE, window, renderer)
		|| !SDL_SetRenderLogicalPresentation(*renderer, data->norm.window_width, data->norm.window_height, SDL_LOGICAL_PRESENTATION_LETTERBOX)
		|| !SDL_SetRenderVSync(*renderer, 1))
		return (data->err.visu_errors |= E_VISU, 1);

	*map_cache = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_TARGET, data->norm.window_width, data->norm.window_height);
	if (!*map_cache)
		return (data->err.visu_errors |= E_VISU, 1);

	return (0);
}
