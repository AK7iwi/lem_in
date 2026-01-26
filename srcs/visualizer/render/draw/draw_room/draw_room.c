#include "lem_in.h"

bool	draw_room(t_data *data, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y)
{
	return (set_colors(data->map, renderer, room)
			|| draw_circle(renderer, data->norm.radius, screen_x, screen_y)
			|| draw_name(renderer, room->name, screen_x, screen_y));
}
