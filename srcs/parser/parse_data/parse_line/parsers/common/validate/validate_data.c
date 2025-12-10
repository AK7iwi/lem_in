#include "lem_in.h"

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

static	bool	is_valid_name(char *line, size_t *i)
{
	size_t	j = (*i);

	if (line[*i] == 'L' || line[*i] == '#') //# already check bottom with isalnum
		return (false);
	while (is_alnum(line[*i]))
		(*i)++;

	return (j < (*i));
}

bool	validate_name(char *line, size_t *i, size_t *name_start, size_t *name_end)
{
	(*name_start) = *i;
	if (!is_valid_name(line, i))
		return (1);
	(*name_end) = *i;

	return (0);
}

bool	is_valid_number(char *line, size_t *i)
{
	size_t	j = (*i);

	while (is_digit(line[*i]))
		(*i)++;

	return (j < (*i));
}
