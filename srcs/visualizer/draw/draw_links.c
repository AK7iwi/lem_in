#include "lem_in.h"

static void	calculate_line_endpoints(float x1, float y1, float x2, float y2,
									float *start_x, float *start_y, float *end_x, float *end_y,
									uint8_t radius)
{
	float	dx;
	float	dy;
	float	distance;
	float	ratio;

	dx = x2 - x1;
	dy = y2 - y1;
	distance = ft_sqrt(dx * dx + dy * dy);

	ratio = radius / distance;
	*start_x = x1 + dx * ratio;
	*start_y = y1 + dy * ratio;
	*end_x = x2 - dx * ratio;
	*end_y = y2 - dy * ratio;
}

void	draw_links(SDL_Renderer *renderer, t_normalize *norm, t_room *room)
{
	t_link	*link;
	float	x1, y1, x2, y2;
	float	start_x, start_y, end_x, end_y; //int for better visu

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	link = room->link;
	while (link)
	{
		// Draw only if current room's address is less than linked room's address
		// Only draw each link once (avoid drawing the same link from both rooms)
		if (room < link->room)
		{
			normalize_coordinates(norm, room->x, &x1, room->y, &y1);
			normalize_coordinates(norm, link->room->x, &x2, link->room->y, &y2);
			calculate_line_endpoints(x1, y1, x2, y2, &start_x, &start_y, &end_x, &end_y, norm->radius);
			SDL_RenderLine(renderer, start_x, start_y, end_x, end_y);	
		}
		link = link->next;
	}
}
