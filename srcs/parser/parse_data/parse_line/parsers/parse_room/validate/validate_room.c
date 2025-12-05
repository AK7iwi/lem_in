#include "lem_in.h"

bool	validate_nb_rooms(t_data *data)
{
	return (data->map->nb_rooms > MAX_ROOMS);
}

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

static	bool	validate_coordinates_values(uint32_t x, uint32_t y)
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

static	bool	validate_room_format(t_data *data, char *line,
										size_t *name_start, size_t *name_end,
										size_t *x_start, size_t *x_end,
										size_t *y_start, size_t *y_end)
{
	size_t	i = 0;

	skip_space(line, &i);
	(*name_start) = i;
	if (!is_valid_name(line, &i)) /* Room's name */
		return (1);
	(*name_end) = i;
	if (is_existing_room(data, line, *name_start, *name_end))
		return (1);
	skip_space(line, &i);
	(*x_start) = i;
	if (!is_valid_number(line, &i)) /* coord_x */
		return (1);
	(*x_end) = i;
	skip_space(line, &i);
	(*y_start) = i;
	if (!is_valid_number(line, &i)) /* coord_y */
		return (1);
	(*y_end) = i;
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (1);

	return (0);
}

bool	validate_room(t_data *data, char *line, char **name, uint32_t *x, uint32_t *y)
{
	size_t	name_start, name_end;
	size_t	x_start, x_end;
	size_t	y_start, y_end;

	if (validate_room_format(data, line, &name_start, &name_end, &x_start, &x_end, &y_start, &y_end))
		return (1);
	if (extract_room(data, line, name, x, y, name_start, name_end, x_start, x_end, y_start, y_end))
		return (1);
	if (validate_coordinates(data, *x, *y))
		return (free(*name), 1);

	return (0);
}
