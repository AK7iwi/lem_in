#include "lem_in.h"

static bool	compare_room_name(char *line, size_t name_start, size_t name_end, char *room_name)
{
	size_t	i;

	i = 0;
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
	size_t	j;

	name_start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '-' 
		   && !(line[*i] >= 9 && line[*i] <= 13) && line[*i] != '\n') //is_last_char
		(*i)++;
	name_end = *i;

	j = 0;
	while (j < data->map->nb_rooms)
	{
		if (compare_room_name(line, name_start, name_end, data->map->rooms[j].name))
			return (&data->map->rooms[j]);
		j++;
	}
	return (NULL);
}

inline	bool	is_end_room(char	*line, size_t	i)
{
	return (line[i] == 'e' && line[i + 1] == 'n' && line[i + 2] == 'd');
}

inline	bool	is_start_room(char	*line, size_t	i)
{
	return (line[i] == 's' && line[i + 1] == 't' && line[i + 2] == 'a'
			&& line[i + 3] == 'r' && line[i + 4] == 't');
}

bool	is_valid_name(t_data	*data, char	*line, size_t	*i)
{
	bool	found_name;
	size_t	j;

	found_name = false;
	j = (*i);
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

bool	is_valid_number(char	*line, size_t	*i)
{
	bool	found_digit;

	found_digit = false;
	while (line[*i] && line[*i] != ' ' && !is_last_char(line[*i]))
	{
		if (!is_digit(line[*i]))
			return (false);
		found_digit = true;
		(*i)++;
	}
	return (found_digit);
}

//tools
void	skip_space(char	*line, size_t	*i)
{
	while (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
}
