#include "lem_in.h"
#include <SDL3/SDL.h>

bool	visualizer(t_data *data)
{
	SDL_Window	    *window;
	SDL_Renderer    *renderer;
	SDL_Event	    event;
	bool		    running;

    //init lib
    // ft_putstr(SDL_GetError(), STDERR_FILENO); // Use for debug
	if (!SDL_Init(SDL_INIT_VIDEO))
		return (data->err.visu_errors |= E_VISU, 1);

	if (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_RESIZABLE, &window, &renderer))
	{
		SDL_Quit();
		return (data->err.visu_errors |= E_VISU, 1);
	}

	SDL_SetRenderLogicalPresentation(renderer, WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    //render fct 
	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				running = false;
		}

		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
		SDL_RenderClear(renderer);

		//Draw here
		SDL_RenderPresent(renderer);
	}

    // Refacto into close_render fct 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
