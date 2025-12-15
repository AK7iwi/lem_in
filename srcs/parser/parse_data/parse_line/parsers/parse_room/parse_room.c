#include "lem_in.h"

bool	parse_room(t_data *data, char *line, bool is_start, bool is_end)
{
	char		*name;
	uint32_t	x, y;

	if (!data->nb_ants && !data->err.parsing_errors)
		return (data->err.parsing_errors |= E_ANTS_AND_ROOMS_MIXED, 1);
	if (data->map->nb_links)
		return (1);
	if (validate_room(data, line, &name, &x, &y))
		return (1);
	if (create_room(data, name, x, y, is_start, is_end))
		return (1);
	if (validate_nb_rooms(data))
		return (data->err.parsing_errors |= E_NB_ROOMS, 1);

	return (0);
}
