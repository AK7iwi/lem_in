#include "lem_in.h"

bool	is_valid_map(t_data *data)
{
	if (!data->map->start_room)
	{
		data->err.parsing_errors |= E_START;
		return (false);
	}
	if (!data->map->end_room)
	{
		data->err.parsing_errors |= E_END;
		return (false);
	}
	if (data->map->nb_links < data->map->nb_rooms - 1)
	{
		data->err.parsing_errors |= E_NB_LINKS;
		return (false);
	}

	return (true);
}
