#include "lem_in.h"

bool	validate_link(t_data *data, char *line, t_room **room1, t_room **room2)
{
	size_t	room1_start, room1_end;
	size_t	room2_start, room2_end;
	char 	*room1_name, *room2_name;

	if (validate_link_format(line, &room1_start, &room1_end, &room2_start, &room2_end))
		return (1);
	if (extract_room_names(&data->err, line, &room1_name, room1_start, room1_end, &room2_name, room2_start, room2_end))
		return (1);
	if (validate_link_values(data, room1, room1_name, room2, room2_name))
	{
		free_room_names(room1_name, room2_name);
		return (1);
	}
	free_room_names(room1_name, room2_name);

	return (0);
}
