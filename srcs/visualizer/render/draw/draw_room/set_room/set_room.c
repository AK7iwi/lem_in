#include "lem_in.h"

bool	set_colors(t_map *map, SDL_Renderer *renderer, t_room *room)
{
	uint8_t r = 0, g = 0, b = 0;

	if (room == map->start_room)
		g = 255;
	else if (room == map->end_room)
		r = 255;
	else
	{
		r = 255;
		g = 255;
		b = 255;
	}

	return (!SDL_SetRenderDrawColor(renderer, r, g, b, 255));
}
