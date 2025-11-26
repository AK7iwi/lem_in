#include "lem_in.h"

t_room	*find_start_room(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_rooms)
	{
		if (map->rooms[i].is_start)
			return (&map->rooms[i]);
		i++;
	}
	return (NULL);
}

t_room	*find_end_room(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_rooms)
	{
		if (map->rooms[i].is_end)
			return (&map->rooms[i]);
		i++;
	}
	return (NULL);
}
