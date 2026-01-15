#include "lem_in.h"

static	bool	present_frame(SDL_Renderer *renderer, SDL_Texture *map_cache)
{
	return (!SDL_RenderTexture(renderer, map_cache, NULL, NULL)
			|| !SDL_RenderPresent(renderer));
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

	if ( !SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
		|| !SDL_RenderClear(renderer)
		|| !SDL_SetRenderScale(renderer, data->norm.zoom, data->norm.zoom)
		|| draw_render(data, renderer))
	{
		SDL_SetRenderTarget(renderer, NULL);
		return (1);
	}

	return (!SDL_SetRenderTarget(renderer, NULL));
}

bool	render(t_data *data, SDL_Renderer *renderer, SDL_Texture *map_cache)
{
	bool			running = true;

	if (render_to_cache(data, renderer, map_cache))
		return (data->err.visu_errors |= E_VISU, 1);

	while (running)
	{
		if (event_handler(data))
			running = false;
		if (needs_cache_update(data))
			if (render_to_cache(data, renderer, map_cache))
				return (data->err.visu_errors |= E_VISU, 1);
		if (present_frame(renderer, map_cache))
			return (data->err.visu_errors |= E_VISU, 1);
	}
	
	return (0);
}
