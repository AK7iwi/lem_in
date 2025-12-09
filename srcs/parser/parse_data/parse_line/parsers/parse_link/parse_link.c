#include "lem_in.h"

bool	parse_link(t_data *data, char *line)
{
	t_room	*room1, *room2;

	if (validate_link(data, line, &room1, &room2))
		return (1);
	if (create_link(data, room1, room2))
		return (1);

	return (0);
}
