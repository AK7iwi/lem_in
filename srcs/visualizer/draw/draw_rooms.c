#include "lem_in.h"

static  void	draw_circle(SDL_Renderer *renderer, int center_x, int center_y, int radius)
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

static  void	draw_room_name(SDL_Renderer *renderer, char *text, int x, int y)
{
	int		text_width;
	int		offset_x;

	text_width = ft_strlen(text) * 8;
	offset_x = text_width / 2;
	
	SDL_RenderDebugText(renderer, x - offset_x, y - 4, text);
}

void	draw_rooms(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	int	screen_x, screen_y;

	normalize_coordinates(data->norm, room->x, &screen_x, room->y, &screen_y);

	// fct colors 
	if (room == data->map->start_room)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for start
	else if (room == data->map->end_room)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for end
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gray for normal rooms

	draw_circle(renderer, screen_x, screen_y, CIRCLE_RADIUS);
	draw_room_name(renderer, room->name, screen_x, screen_y);
}
