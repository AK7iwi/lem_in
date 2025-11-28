#include "lem_in.h"

bool	is_existing_link(t_room	*room, t_room	*target_room)
{
	t_room_link	*current;

	current = room->link;
	while (current)
	{
		if (current->room == target_room)
			return (true);
		current = current->next;
	}
	return (false);
}