#include "lem_in.h"
#include <SDL3/SDL.h>

void	draw_render(SDL_Renderer *renderer, t_data *data)
{
	size_t		i;
	t_room		*room;
	t_normalize	norm;

	calculate_normalization(data, &norm);
	i = 0;
	while (i < data->map->nb_rooms)
	{
		room = &data->map->rooms[i];
		draw_rooms(renderer, data, room, &norm);
		draw_links(renderer, room, &norm);
		i++;
	}
}
