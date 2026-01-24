#include "lem_in.h"

static	bool	is_existing_coordinates(t_data *data, uint32_t x, uint32_t y)
{
	size_t	i = 0;

	while (i < data->map->nb_rooms)
	{
		if (data->map->rooms[i].x == x && data->map->rooms[i].y == y)
			return (true);
		i++;
	}

	return (false);
}

static	inline	bool	validate_coordinates_values(uint32_t x, uint32_t y)
{
	return (x > MAX_COORDINATE || y > MAX_COORDINATE);
}

static	bool	validate_coordinates(t_data *data, uint32_t x, uint32_t y)
{
	if (validate_coordinates_values(x, y))
	{
		data->err.parsing_errors |= E_COORDS_VALUES;
		return (1);
	}
	if (is_existing_coordinates(data, x, y))
	{
		data->err.parsing_errors |= E_COORDS_EXIST;
		return (1);
	}

	return (0);
}

bool    validate_room_values(t_data *data, char *name, uint32_t x, uint32_t y)
{
	if (is_existing_room(data, name))
	{
		data->err.parsing_errors |= E_ROOM_EXISTS;
		return (1);
	}
	if (validate_coordinates(data, x, y))
		return (1);

	return (0);
}
