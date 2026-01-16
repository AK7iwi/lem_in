#include "lem_in.h"

static	void	calculate_line_endpoints(float x1, float y1, float x2, float y2,
									 	 float *start_x, float *start_y, float *end_x, float *end_y,
									 	 float radius, float length)
{
	float	dx, dy, ratio;

	dx = x2 - x1;
	dy = y2 - y1;

	ratio = radius / length;
	*start_x = x1 + dx * ratio;
	*start_y = y1 + dy * ratio;
	*end_x = x2 - dx * ratio;
	*end_y = y2 - dy * ratio;
}

static	void	calculate_line_normal(float x1, float y1, float x2, float y2,
									  float *length, float *perp_x, float *perp_y)
{
	float	dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;

	*length = ft_sqrt(dx * dx + dy * dy);
	*perp_x = -dy / *length;
	*perp_y = dx / *length;
}

bool	draw_links(t_normalize *norm, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y)
{
	t_link	*link;
	float	screen_x2, screen_y2;
	float	start_x, start_y, end_x, end_y;
	float	length, perp_x, perp_y;

	link = room->link;
	while (link)
	{
		if (room < link->room)
		{
			transform_coords(norm, link->room->x, link->room->y, &screen_x2, &screen_y2);
			calculate_line_normal(screen_x, screen_y, screen_x2, screen_y2, &length, &perp_x, &perp_y);
			calculate_line_endpoints(screen_x, screen_y, screen_x2, screen_y2, &start_x, &start_y, &end_x, &end_y, norm->radius, length);
			if (draw_corridor(renderer, start_x, start_y, end_x, end_y, norm->radius, perp_x, perp_y))
				return (1);
		}
		link = link->next;
	}

	return (0);
}
