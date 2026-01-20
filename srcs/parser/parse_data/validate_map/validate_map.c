#include "lem_in.h"

bool	is_valid_map(t_data *data)
{
	if (!data->map->start_room)
		return (data->err.parsing_errors |= E_START, false);
	if (!data->map->end_room)
		return (data->err.parsing_errors |= E_END, false);
	if (data->map->nb_links < data->map->nb_rooms - 1)
		return (data->err.parsing_errors |= E_NB_LINKS, false);
	if (!has_path(data)) /* BFS algo */
		return (data->err.parsing_errors |= E_NO_PATH, false);

	return (true);
}
