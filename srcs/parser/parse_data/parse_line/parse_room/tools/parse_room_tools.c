#include "lem_in.h"

bool	is_existing_coordinates(t_data *data, uint16_t x, uint16_t y)
{
	size_t	i;

	i = 0;
	while (i < data->map->nb_rooms)
	{
		if (data->map->rooms[i].x == x && data->map->rooms[i].y == y)
			return (true); //error 
		i++;
	}
	return (false);
}

bool	is_valid_name(t_data	*data, char	*line, size_t	*i)
{
	bool	found_name = false;
	size_t	j = (*i);

	if (line[*i] == 'L' || line[*i] == '#')
		return (false);
	while (line[*i] && line[*i] != ' ') //&& !(line[*i] >= 9 && line[*i] <= 13)
	{
		if (!is_alnum(line[*i]))
			return (false);
		found_name = true;
		(*i)++;
	}
	return (found_name && !is_existing_room(data, line, &j));
}
