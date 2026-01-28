#include "lem_in.h"

bool	draw_render(t_data *data, SDL_Renderer *renderer)
{
	size_t	i = 0;
	t_room	*room;
	float	screen_x, screen_y;

	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		transform_coords(&data->norm, room->x, room->y, &screen_x, &screen_y);
		if (draw_room(data, renderer, room, screen_x, screen_y)
		 || draw_link(&data->norm, renderer, room, screen_x, screen_y))
			return (1);
		i++;
	}

	return (0);
}
