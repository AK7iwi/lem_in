#include "lem_in.h"

inline	size_t	get_room_index(t_map	*map, t_room	*room)
{
	return (room - map->rooms);
}