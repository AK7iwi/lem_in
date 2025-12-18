#include "lem_in.h"
#include <SDL3/SDL.h>

static  void	close_render(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static	bool	render_event()
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
			return (1);
	}

	return (0);
}

static	void	render(SDL_Renderer *renderer, t_data *data)
{
	bool	running = true;

	while (running)
	{
		if (render_event())
			running = false;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		draw_render(renderer, data);
		SDL_RenderPresent(renderer);
	}
}

static  bool	init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		return (data->err.visu_errors |= E_VISU, 1);
	if (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_RESIZABLE, window, renderer))
	{
		SDL_Quit();
		return (data->err.visu_errors |= E_VISU, 1);
	}

	SDL_SetRenderLogicalPresentation(*renderer, WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_LOGICAL_PRESENTATION_LETTERBOX);

	return (0);
}

bool	visualizer(t_data *data)
{
	SDL_Window	    *window;
	SDL_Renderer    *renderer;

	if (init_render(data, &window, &renderer))
		return (1);

	render(renderer, data);
	close_render(window, renderer);

	return (0);
}
