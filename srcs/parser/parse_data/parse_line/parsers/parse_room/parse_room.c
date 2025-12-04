#include "lem_in.h"

bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end)
{
	char		*name;
	uint32_t	x, y;

	if (data->map->nb_links)
		return (1); //error: rooms and links mixed

	if (validate_room(data, line, &name, &x, &y))
		return (1);
	if (create_room(data, name, x, y, is_start, is_end))
		return (1);

	return (0);
}
