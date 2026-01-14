#include "lem_in.h"

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
