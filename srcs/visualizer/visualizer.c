#include "lem_in.h"
#include <SDL3/SDL.h>

static	void	draw_links(SDL_Renderer *renderer, t_data *data)
{
	t_link	*link;
	size_t	i = 0;

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	while (i < data->map->nb_rooms)
	{
		link = data->map->rooms[i].link;
		while (link)
		{
			SDL_RenderLine(renderer,
				data->map->rooms[i].x * SCALE + PADDING,
				data->map->rooms[i].y * SCALE + PADDING,
				link->room->x * SCALE + PADDING,
				link->room->y * SCALE + PADDING);
			link = link->next;
		}
		i++;
	}
}

static	void	draw_rooms(SDL_Renderer *renderer, t_data *data)
{
	size_t	i = 0;
	t_room	*room;

	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		
		// Set color based on room type
		if (room == data->map->start_room)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for start
		else if (room == data->map->end_room)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for end
		else
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gray for normal rooms
		
		// Draw room as a filled circle (approximated with points)
		for (int w = -5; w <= 5; w++)
		{
			for (int h = -5; h <= 5; h++)
			{
				if (w * w + h * h <= 25) // Circle equation
					SDL_RenderPoint(renderer,
						room->x * SCALE + PADDING + w,
						room->y * SCALE + PADDING + h);
			}
		}
		i++;
	}
}

static	void	draw_render(SDL_Renderer *renderer, t_data *data)
{	
	draw_links(renderer, data);
	draw_rooms(renderer, data);
}

static  void	close_render(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static  void	render(SDL_Renderer *renderer, t_data *data)
{
	SDL_Event	event;
	bool		running;

	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				running = false;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		draw_render(renderer, data);
		SDL_RenderPresent(renderer);
	}
}

static  bool	init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer)
{
	// ft_putstr(SDL_GetError(), STDERR_FILENO); // Use for debug
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
