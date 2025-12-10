#include "lem_in.h"

bool	validate_cmd_and_cmt_value(t_data *data, bool is_start, bool is_end)
{
	if (is_start && data->map->start_room)
		return (1); //two start error
	else if (is_end && data->map->end_room)
		return (1); //two end error

	return (0);
}