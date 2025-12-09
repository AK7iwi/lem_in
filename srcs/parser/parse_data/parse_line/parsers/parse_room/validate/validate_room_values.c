#include "lem_in.h"

static	bool	is_existing_coordinates(t_data *data, uint32_t x, uint32_t y)
{
	size_t	i = 0;

	while (i < data->map->nb_rooms)
	{
		if (data->map->rooms[i].x == x && data->map->rooms[i].y == y)
			return (true); //error 
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
		return (1);
	if (is_existing_coordinates(data, x, y))
		return (1);

	return (0);
}

static	bool	compare_room_name(char *name, char *room_name)
{
	size_t i = 0;

	while (name[i] && room_name[i])
	{
		if (name[i] != room_name[i])
			return (false);
		i++;
	}

	return (true);
}

t_room	*is_existing_room(t_data *data, char *name)
{
	size_t i = 0;

	while (i < data->map->nb_rooms)
	{
		if (compare_room_name(name, data->map->rooms[i].name))
			return (&data->map->rooms[i]);
		i++;
	}

	return (NULL);
}

bool    validate_room_values(t_data *data, char *name, uint32_t x, uint32_t y)
{
	if (is_existing_room(data, name))
		return (1);
	if (validate_coordinates(data, x, y))
		return (1);

	return (0);
}
