#include "lem_in.h"

bool	validate_cmd_and_cmt_value(t_data *data, bool is_start, bool is_end)
{
	if (is_start && data->map->start_room)
		return (data->err.parsing_errors |= E_TWO_STARTS, 1);
	else if (is_end && data->map->end_room)
		return (data->err.parsing_errors |= E_TWO_ENDS, 1);

	return (0);
}