#include "lem_in.h"

bool	draw_render(t_data *data, SDL_Renderer *renderer)
{
	size_t		i = 0;
	t_room		*room;

	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		if (draw_rooms(data, renderer, room) || draw_links(&data->norm, renderer, room))
			return (1);
		i++;
	}

	return (0);
}
