#include "lem_in.h"
#include <SDL3/SDL.h>

static	void	draw_circle(SDL_Renderer *renderer, int center_x, int center_y, int radius)
{
	int x = 0;
	int y = radius;
	int d = 1 - radius;

	while (x <= y)
	{
		SDL_RenderPoint(renderer, center_x + x, center_y + y);
		SDL_RenderPoint(renderer, center_x - x, center_y + y);
		SDL_RenderPoint(renderer, center_x + x, center_y - y);
		SDL_RenderPoint(renderer, center_x - x, center_y - y);
		SDL_RenderPoint(renderer, center_x + y, center_y + x);
		SDL_RenderPoint(renderer, center_x - y, center_y + x);
		SDL_RenderPoint(renderer, center_x + y, center_y - x);
		SDL_RenderPoint(renderer, center_x - y, center_y - x);

		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

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

		if (room == data->map->start_room)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for start
		else if (room == data->map->end_room)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for end
		else
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gray for normal rooms

		draw_circle(renderer, room->x * SCALE + PADDING, room->y * SCALE + PADDING, 10);
		i++;
	}
}

void	draw_render(SDL_Renderer *renderer, t_data *data)
{	
	draw_links(renderer, data);
	draw_rooms(renderer, data);
}
