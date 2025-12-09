#include "lem_in.h"

bool	validate_link(t_data *data, char *line, t_room **room1, t_room **room2)
{
	char 	*room1_name, *room2_name;
	size_t	room1_start, room1_end;
	size_t	room2_start, room2_end;

	if (validate_link_format(data, line, &room1_start, &room1_end, &room2_start, &room2_end))
		return (1);
	//extract fct
	room1_name = extract_name(line, room1_start, room1_end);
	if (!room1_name)
		return (1);
	room2_name = extract_name(line, room2_start, room2_end);
	if (!room2_name)
		return (free(room1_name), 1);
	if (validate_link_values(data, room1, room1_name, room2, room2_name))
		return (free(room1_name), free(room2_name), 1);
	//free fct 
	free(room1_name);
	free(room2_name);
	return (0);
}
