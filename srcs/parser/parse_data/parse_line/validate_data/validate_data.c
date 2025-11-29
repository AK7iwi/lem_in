#include "lem_in.h"

static bool	compare_room_name(char	*line, size_t	name_start, size_t	name_end, char	*room_name)
{
	size_t	i = 0;

	while (name_start < name_end && room_name[i])
	{
		if (line[name_start] != room_name[i])
			return (false);
		name_start++;
		i++;
	}
	return (name_start == name_end && room_name[i] == '\0');
}

t_room	*is_existing_room(t_data	*data, char	*line, size_t	*i)
{
	size_t	name_start;
	size_t	name_end;
	size_t	j = 0;

	name_start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '-' 
		   && !(line[*i] >= 9 && line[*i] <= 13) && line[*i] != '\n')
		(*i)++;
	name_end = *i;

	while (j < data->map->nb_rooms)
	{
		if (compare_room_name(line, name_start, name_end, data->map->rooms[j].name))
			return (&data->map->rooms[j]);
		j++;
	}
	return (NULL);
}

bool	is_valid_number(char	*line, size_t	*i)
{
	bool	found_digit = false;

	while (line[*i] && line[*i] != ' ' && !is_last_char(line[*i]))
	{
		if (!is_digit(line[*i]))
			return (false);
		found_digit = true;
		(*i)++;
	}
	return (found_digit);
}
