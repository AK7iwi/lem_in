#include "lem_in.h"

bool	parse_data(t_data *data, int fd)
{
	if (parse_map(data, fd))
		return (1);
	if (!is_valid_map(data))
		return (1); 
	set_start_room(data);

	return (0);
}
