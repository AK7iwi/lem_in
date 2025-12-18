#include "lem_in.h"

static void	calculate_line_endpoints(int x1, int y1, int x2, int y2,
									int *start_x, int *start_y,
									int *end_x, int *end_y)
{
	float	dx;
	float	dy;
	float	distance;
	float	ratio;

	dx = (float)(x2 - x1);
	dy = (float)(y2 - y1);
	distance = sqrtf(dx * dx + dy * dy);

	// Calculate how much to move from center (circle radius / total distance)
	ratio = CIRCLE_RADIUS / distance;

	// Move start point away from center by circle radius
	*start_x = x1 + (int)(dx * ratio);
	*start_y = y1 + (int)(dy * ratio);

	// Move end point toward center by circle radius
	*end_x = x2 - (int)(dx * ratio);
	*end_y = y2 - (int)(dy * ratio);
}

void	draw_links(SDL_Renderer *renderer, t_normalize *norm, t_room *room)
{
	t_link	*link;
	int		x1, y1, x2, y2;
	int		start_x, start_y, end_x, end_y;

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	link = room->link;
	while (link)
	{
		// Only draw each link once (avoid drawing the same link from both rooms)
		// Draw only if current room's address is less than linked room's address
		if (room < link->room)
		{
			normalize_coordinates(norm, room->x, &x1, room->y, &y1);
			normalize_coordinates(norm, link->room->x, &x2, link->room->y, &y2);
			calculate_line_endpoints(x1, y1, x2, y2, &start_x, &start_y, &end_x, &end_y);
			SDL_RenderLine(renderer, start_x, start_y, end_x, end_y);
		}
		link = link->next;
	}
}
