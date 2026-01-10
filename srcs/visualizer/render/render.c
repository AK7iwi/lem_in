#include "lem_in.h"

void	close_render(SDL_Window *window, SDL_Renderer *renderer)
{
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
}

bool	render(SDL_Renderer *renderer, t_data *data)
{
	bool	running = true;

	while (running)
	{
		if (render_event(data))
			running = false;
		if (!SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
			|| !SDL_RenderClear(renderer)
			|| !SDL_SetRenderScale(renderer, data->norm.zoom, data->norm.zoom)
			|| draw_render(renderer, data)
			|| !SDL_RenderPresent(renderer))
			return (data->err.visu_errors |= E_VISU, 1);
	}
	
	return (0);
}

bool    init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer)
{
	const SDL_DisplayMode	*display_mode;

	if (!SDL_Init(SDL_INIT_VIDEO))
		return (data->err.visu_errors |= E_VISU, 1);

	/* Use 90% of screen size */
	display_mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
	if (!display_mode)
		return (data->err.visu_errors |= E_VISU, 1);
	data->norm.window_width = (uint16_t)(display_mode->w * 0.9f);
	data->norm.window_height = (uint16_t)(display_mode->h * 0.9f);

	if (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", data->norm.window_width, data->norm.window_height, SDL_WINDOW_RESIZABLE, window, renderer)
		|| !SDL_SetRenderLogicalPresentation(*renderer, data->norm.window_width, data->norm.window_height, SDL_LOGICAL_PRESENTATION_LETTERBOX))
		return (data->err.visu_errors |= E_VISU, 1);

	return (0);
}
