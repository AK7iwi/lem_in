#include "lem_in.h"

static	bool	is_existing_link(t_room	*room, t_room	*target_room)
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

bool	validate_link(t_data *data, char *line, t_room **room1, t_room **room2)
{
	size_t	i = 0;
	size_t	room_start, room_end;

	skip_space(line, &i);
	room_start = i;
	if (!is_valid_name(line, &i))
		return (1);
	room_end = i;
	(*room1) = is_existing_room(data, line, room_start, room_end);
	if (!(*room1))
		return (1);
	skip_space(line, &i);
	if (line[i] != '-')
		return (1);
	i++;
	skip_space(line, &i);
	room_start = i;
	if (!is_valid_name(line, &i))
		return (1);
	room_end = i;
	(*room2) = is_existing_room(data, line, room_start, room_end);
	if (!(*room2))
		return (1);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (1);

	if (is_existing_link((*room1), (*room2)))
		return (1);

	return (0);
}