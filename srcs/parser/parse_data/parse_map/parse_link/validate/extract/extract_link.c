#include "lem_in.h"

bool	extract_room_names(t_data *data, char *line, char **room1_name, size_t room1_start, size_t room1_end, char **room2_name, size_t room2_start, size_t room2_end)
{
	*room1_name = extract_name(data, line, room1_start, room1_end);
	if (!*room1_name)
		return (1);
	*room2_name = extract_name(data, line, room2_start, room2_end);
	if (!*room2_name)
	{
		free(*room1_name);
		return (1);
	}

	return (0);
}
