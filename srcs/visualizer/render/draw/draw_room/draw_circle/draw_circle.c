#include "lem_in.h"

static	bool	draw_circle_points(SDL_Renderer *renderer, float center_x, float center_y, float x, float y)
{
	return (!SDL_RenderPoint(renderer, center_x + x, center_y + y)
		 || !SDL_RenderPoint(renderer, center_x - x, center_y + y)
		 || !SDL_RenderPoint(renderer, center_x + x, center_y - y)
		 || !SDL_RenderPoint(renderer, center_x - x, center_y - y)
		 || !SDL_RenderPoint(renderer, center_x + y, center_y + x)
		 || !SDL_RenderPoint(renderer, center_x - y, center_y + x)
		 || !SDL_RenderPoint(renderer, center_x + y, center_y - x)
		 || !SDL_RenderPoint(renderer, center_x - y, center_y - x));
}

bool	draw_circle(SDL_Renderer *renderer, float radius, float center_x, float center_y)
{
	float x = 0;
	float y = radius;
	float d = 1 - radius;

	while (x <= y)
	{
		if (draw_circle_points(renderer, center_x, center_y, x, y))
			return (1);

		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}

	return (0);
}
