#include "lem_in.h"

static  uint16_t	count_path_len(t_map *map, t_room **parent)
{
	t_room		*current;
	uint16_t	len;

	len = 0;
	current = map->end_room;
	while (current != map->start_room)
	{
		len++;
		current = parent[get_room_index(map, current)];
	}
	len++;

	return (len);
}

bool	store_path(t_data *data, t_room **parent, bool *used_rooms, t_pathset *pathset, uint16_t path_idx)
{
	t_room		*current;
	uint16_t	i;

	pathset->paths[path_idx].len = count_path_len(data->map, parent);
	pathset->paths[path_idx].rooms = malloc(sizeof(t_room *) * pathset->paths[path_idx].len);
	if (!pathset->paths[path_idx].rooms)
	{
		data->err.gen_errors |= E_MEMORY;
		return (false);
	}

	current = data->map->end_room;
	i = pathset->paths[path_idx].len;
	while (current != data->map->start_room)
	{
		pathset->paths[path_idx].rooms[--i] = current;
		
		if (current != data->map->end_room && current != data->map->start_room)
			used_rooms[get_room_index(data->map, current)] = true;
		
		current = parent[get_room_index(data->map, current)];
	}
	pathset->paths[path_idx].rooms[0] = data->map->start_room;

	return (true);
}
