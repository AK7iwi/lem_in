#include "lem_in.h"

bool	has_start_or_end_room(t_data *data, bool is_start, bool is_end) //rename
{
	if (is_start && data->map->start_room)
		return (1); //two start error
	else if (is_end && data->map->end_room)
		return (1); //two end error

	return (0);
}