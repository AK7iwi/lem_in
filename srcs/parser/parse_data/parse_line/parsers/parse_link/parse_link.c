#include "lem_in.h"

bool	parse_link(t_data *data, char *line)
{
	t_room	*room1, *room2;

	if (!data->nb_ants && !data->err.parsing_errors)
		return (data->err.parsing_errors |= E_ANTS_AND_LINKS_MIXED, 1);
	if (!data->map->nb_rooms) // maybe too specific error. 
		return (data->err.parsing_errors |= E_ROOMS_AND_LINKS_MIXED, 1);
	if (validate_link(data, line, &room1, &room2))
		return (1);
	if (create_link(data, room1, room2))
		return (1);

	return (0);
}
