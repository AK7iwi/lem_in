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

static  void	draw_text_centered(SDL_Renderer *renderer, char *text, int x, int y)
{
	size_t	len;
	int		text_width;
	int		offset_x;

	len = ft_strlen(text);
	
	// Each character is approximately 8 pixels wide in debug font
	text_width = len * 8;
	offset_x = text_width / 2;
	
	// Center the text (debug font height is ~8 pixels)
	SDL_RenderDebugText(renderer, x - offset_x, y - 4, text);
}

void	draw_rooms(SDL_Renderer *renderer, t_data *data, t_room *room, t_normalize *norm)
{
	int	screen_x;
	int	screen_y;

	screen_x = normalize_x(room->x, norm);
	screen_y = normalize_y(room->y, norm);

	if (room == data->map->start_room)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for start
	else if (room == data->map->end_room)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for end
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Gray for normal rooms

	draw_circle(renderer, screen_x, screen_y, CIRCLE_RADIUS);

	// rename draw_room_name
	draw_text_centered(renderer, room->name, screen_x, screen_y);
}
