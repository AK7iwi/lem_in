#include "lem_in.h"

static bool	add_link_to_room(t_data *data, t_room *room, t_room *target_room)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (!new_link)
		return (data->err.gen_errors |= E_MEMORY, 1);
	
	new_link->room = target_room;
	new_link->pheromones_rate = 0;
	new_link->next = room->link;
	room->link = new_link;

	return (0);
}

bool	create_link(t_data *data, t_room *room1, t_room *room2)
{
	if (add_link_to_room(data, room1, room2) || add_link_to_room(data, room2, room1))
		return (1);
	data->map->nb_links++;

	return (0);
}
