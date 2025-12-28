#include "lem_in.h"

static  void	draw_room_name(SDL_Renderer *renderer, char *text, float x, float y)
{
	uint8_t		text_width;
	float		offset_x;

	text_width = ft_strlen(text) * 8;
	offset_x = text_width / 2;
	
	SDL_RenderDebugText(renderer, x - offset_x, y - 4, text);
}

static  void	draw_circle(SDL_Renderer *renderer, float center_x, float center_y, uint8_t radius)
{
	float x = 0; // uint
	float y = radius; //uint
	float d = 1 - radius; //uint

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

static	void	set_colors(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	if (room == data->map->start_room)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); /* Green for start */
	else if (room == data->map->end_room)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); /* Red for end */
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); /* Gray for normal rooms */
}

void	draw_rooms(SDL_Renderer *renderer, t_data *data, t_room *room)
{
	float	screen_x, screen_y;

	set_colors(renderer, data, room);
	normalize_coordinates(&data->norm, room->x, &screen_x, room->y, &screen_y);
	draw_circle(renderer, screen_x, screen_y, data->norm.radius);
	
	// if (data->map->nb_rooms < 100 || room == data->map->start_room || room == data->map->end_room)
	draw_room_name(renderer, room->name, screen_x, screen_y);
}
