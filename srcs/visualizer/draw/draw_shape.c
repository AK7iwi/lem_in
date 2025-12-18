#include "lem_in.h"
#include <SDL3/SDL.h>

void	draw_circle(SDL_Renderer *renderer, int center_x, int center_y, int radius)
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
