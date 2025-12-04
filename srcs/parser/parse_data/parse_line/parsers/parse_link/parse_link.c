#include "lem_in.h"

bool	parse_link(t_data *data, char *line)
{
	size_t	i = 0;
	t_room	*room1, *room2;
	size_t	room_start, room_end;

	//check that there is room
	
	skip_space(line, &i);
	room_start = i;
	if (!is_valid_name(line, &i))
		return (1);
	room_end = i;
	room1 = is_existing_room(data, line, room_start, room_end);
	if (!room1)
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
	room2 = is_existing_room(data, line, room_start, room_end);
	if (!room2)
		return (1);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (1);
	if (is_existing_link(room1, room2) || create_link(data, room1, room2))
		return (1);
	return(0);
}
