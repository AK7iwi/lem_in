#include "lem_in.h"
#include <SDL3/SDL.h>

static	void	draw_links(SDL_Renderer *renderer, t_room *room)
{
	t_link *link = room->link;

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	while (link)
	{
		SDL_RenderLine(renderer,
			room->x + PADDING,
			room->y + PADDING,
			link->room->x + PADDING,
			link->room->y + PADDING);
		link = link->next;
	}
}

static	void	draw_rooms(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	if (room == data->map->start_room)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for start
	else if (room == data->map->end_room)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for end
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gray for normal rooms

	draw_circle(renderer, room->x + PADDING, room->y + PADDING, CIRCLE_RADIUS);
}

void	draw_render(SDL_Renderer *renderer, t_data *data)
{
	size_t	i = 0;
	t_room	*room;

	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		draw_rooms(renderer, data, room);
		draw_links(renderer, room);
		i++;
	}
}
