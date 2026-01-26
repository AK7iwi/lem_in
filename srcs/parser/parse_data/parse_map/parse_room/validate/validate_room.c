#include "lem_in.h"

inline	bool	validate_nb_rooms(t_map *map)
{
	return (map->nb_rooms > MAX_ROOMS);
}

bool	validate_room(t_data *data, char *line, char **name, uint32_t *x, uint32_t *y)
{
	size_t	name_start, name_end;
	size_t	x_start, x_end;
	size_t	y_start, y_end;

	if (validate_room_format(line, &name_start, &name_end, &x_start, &x_end, &y_start, &y_end))
		return (1);
	if (extract_room_data(&data->err, line, name, x, y, name_start, name_end, x_start, x_end, y_start, y_end))
		return (1);
	if (validate_room_values(data, *name, *x, *y))
	{
		free(*name);
		return (1);
	}

	return (0);
}
