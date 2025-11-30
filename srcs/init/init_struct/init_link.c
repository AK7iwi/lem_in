#include "lem_in.h"


static bool	add_link_to_room(t_room *room, t_room *target_room)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (!new_link)
		return (EXIT_FAILURE);
	
	new_link->room = target_room;
	new_link->pheromones_rate = 0;
	new_link->next = room->link;
	room->link = new_link;

	return (EXIT_SUCCESS);
}

bool	init_link(t_room	*room1, t_room	*room2)
{
	if (add_link_to_room(room1, room2) || add_link_to_room(room2, room1))
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
