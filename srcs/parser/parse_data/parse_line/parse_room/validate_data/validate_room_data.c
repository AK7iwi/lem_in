#include "lem_in.h"

bool	is_existing_coordinates(t_data *data, uint32_t x, uint32_t y)
{
	size_t	i;

	i = 0;
	while (i < data->map->nb_rooms)
	{
		if (data->map->rooms[i].x == x && data->map->rooms[i].y == y)
			return (true); //error 
		i++;
	}
	return (false);
}
