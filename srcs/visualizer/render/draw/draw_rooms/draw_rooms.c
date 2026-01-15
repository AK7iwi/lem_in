#include "lem_in.h"

static  bool	draw_room_name(SDL_Renderer *renderer, char *name, float x, float y)
{
	uint8_t		text_width;
	float		offset_x;

	text_width = ft_strlen(name) * 8;
	offset_x = text_width / 2;

	return (!SDL_RenderDebugText(renderer, x - offset_x, y - 4, name));
}

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

static  bool	draw_circle(SDL_Renderer *renderer, float radius, float center_x, float center_y)
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

static	bool	set_colors(t_data *data, SDL_Renderer *renderer, t_room *room)
{
	uint8_t r = 0, g = 0, b = 0;

	if (room == data->map->start_room)
		g = 255;
	else if (room == data->map->end_room)
		r = 255;
	else
	{
		r = 255;
		g = 255;
		b = 255;
	}

	return (!SDL_SetRenderDrawColor(renderer, r, g, b, 255));
}

bool	draw_rooms(t_data *data, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y)
{
	return (set_colors(data, renderer, room)
			|| draw_circle(renderer, data->norm.radius, screen_x, screen_y)
			|| draw_room_name(renderer, room->name, screen_x, screen_y));
}
