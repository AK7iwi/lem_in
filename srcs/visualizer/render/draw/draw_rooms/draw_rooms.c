#include "lem_in.h"

static  bool	draw_room_name(SDL_Renderer *renderer, char *text, float x, float y)
{
	uint8_t		text_width;
	float		offset_x;

	text_width = ft_strlen(text) * 8;
	offset_x = text_width / 2;
	
	return (!SDL_RenderDebugText(renderer, x - offset_x, y - 4, text));
}

static  bool	draw_circle(SDL_Renderer *renderer, float center_x, float center_y, float radius)
{
	float x = 0;
	float y = radius;
	float d = 1 - radius;

	while (x <= y)
	{
		if (!SDL_RenderPoint(renderer, center_x + x, center_y + y)
			|| !SDL_RenderPoint(renderer, center_x - x, center_y + y)
			|| !SDL_RenderPoint(renderer, center_x + x, center_y - y)
			|| !SDL_RenderPoint(renderer, center_x - x, center_y - y)
			|| !SDL_RenderPoint(renderer, center_x + y, center_y + x)
			|| !SDL_RenderPoint(renderer, center_x - y, center_y + x)
			|| !SDL_RenderPoint(renderer, center_x + y, center_y - x)
			|| !SDL_RenderPoint(renderer, center_x - y, center_y - x))
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

static	bool	set_colors(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	uint8_t r, g, b;

	r = 0;
	g = 0;
	b = 0;

	if (room == data->map->start_room)
		g = 255; /* Green for end */ 
	else if (room == data->map->end_room)
		r = 255; /* Red for end */
	else /* Gray for normal rooms */
	{
		r = 200;
		g = 200;
		b = 200;
	}

	return (!SDL_SetRenderDrawColor(renderer, r, g, b, 255));
}

bool	draw_rooms(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	float	screen_x, screen_y;

	if (set_colors(renderer, data, room))
		return (1);
	normalize_coordinates(&data->norm, room->x, &screen_x, room->y, &screen_y);
	if (draw_circle(renderer, screen_x, screen_y, data->norm.radius) 
		|| draw_room_name(renderer, room->name, screen_x, screen_y))	
		return (1);

	return (0);
}
