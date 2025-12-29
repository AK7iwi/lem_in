#include "lem_in.h"
#include <SDL3/SDL.h>

void	draw_render(SDL_Renderer *renderer, t_data *data)
{
	size_t		i = 0;
	t_room		*room;

	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		draw_rooms(renderer, data, room);
		draw_links(renderer, &data->norm, room);
		i++;
	}
}
