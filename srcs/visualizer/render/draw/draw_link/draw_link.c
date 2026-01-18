#include "lem_in.h"

bool	draw_link(t_normalize *norm, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y)
{
	t_link	*link;
	float	start_x, start_y, end_x, end_y;
	float	length, perp_x, perp_y;

	link = room->link;
	while (link)
	{
		if (room < link->room)
		{
			set_corridor(norm, link, screen_x, screen_y, &start_x, &start_y, &end_x, &end_y, &length, &perp_x, &perp_y);
			if (draw_corridor(renderer, start_x, start_y, end_x, end_y, norm->radius, perp_x, perp_y))
				return (1);
		}
		link = link->next;
	}

	return (0);
}
