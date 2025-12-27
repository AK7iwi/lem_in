#include "lem_in.h"

static	bool	is_existing_link(t_room	*room, t_room *target_room)
{
	t_link	*current;

	current = room->link;
	while (current)
	{
		if (current->room == target_room)
			return (true);
		current = current->next;
	}
	return (false);
}

static	inline	bool	are_same_room(t_room *room1, t_room *room2)
{
	return (room1 == room2);
}

bool	validate_link_values(t_data *data, t_room **room1, char *room1_name, t_room **room2, char *room2_name)
{
	*room1 = is_existing_room(data, room1_name);
	if (!(*room1))
		return (data->err.parsing_errors |= E_ROOM_NOT_FOUND, 1);
	*room2 = is_existing_room(data, room2_name);
	if (!(*room2))
		return (data->err.parsing_errors |= E_ROOM_NOT_FOUND, 1);
	if (are_same_room(*room1, *room2))
		return (data->err.parsing_errors |= E_SAME_ROOM, 1);
	if (is_existing_link(*room1, *room2))
		return (data->err.parsing_errors |= E_LINK_EXISTS, 1);

	return (0);
}
