#include "lem_in.h"

static char	*extract_room_name(char *line, size_t *i)
{
	size_t	name_start;
	size_t	name_len;
	char	*name;

	skip_space(line, i);
	name_start = *i;
	
	while (line[*i] && line[*i] != ' ' && !(line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
	
	name_len = *i - name_start;
	if (name_len == 0)
		return (NULL);
	
	name = malloc(sizeof(char) * (name_len + 1));
	if (!name)
		return (NULL);
	
	for (size_t j = 0; j < name_len; j++)
		name[j] = line[name_start + j];
	name[name_len] = '\0';
	
	return (name);
}

static uint16_t	extract_coordinate(char *line, size_t *i)
{
	uint16_t	result;

	result = 0;
	skip_space(line, i);
	while (is_digit(line[*i]))
	{
		result = result * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (result);
}

static bool	allocate_map_if_needed(t_data *data)
{
	if (!data->map)
	{
		data->map = malloc(sizeof(t_map));
		if (!data->map)
			return (false);
		data->map->nb_rooms = 0;
		data->map->rooms = NULL;
		data->map->start_room = NULL;
		data->map->end_room = NULL;
	}
	return (true);
}

static bool	add_room_to_map(t_data *data, t_room *new_room)
{
	t_room	*new_rooms;
	size_t	new_size;

	new_size = data->map->nb_rooms + 1;
	new_rooms = malloc(sizeof(t_room) * new_size);
	if (!new_rooms)
		return (false);
	
	for (size_t i = 0; i < data->map->nb_rooms; i++)
		new_rooms[i] = data->map->rooms[i];
	
	new_rooms[data->map->nb_rooms] = *new_room;
	
	free(data->map->rooms);
	data->map->rooms = new_rooms;
	data->map->nb_rooms = new_size;
	
	return (true);
}

void	fill_room(t_data *data, char *line, bool is_start, bool is_end)
{
	size_t	i;
	t_room	new_room;

	i = 0;
	
	if (!allocate_map_if_needed(data))
		return;
	
	new_room.name = extract_room_name(line, &i);
	if (!new_room.name)
		return;
	
	new_room.x = extract_coordinate(line, &i);
	new_room.y = extract_coordinate(line, &i);
	
	new_room.is_empty = true;
	new_room.link = NULL;
	
	if (!add_room_to_map(data, &new_room))
	{
		free(new_room.name);
		return;
	}
	
	if (is_start)
		data->map->start_room = &data->map->rooms[data->map->nb_rooms - 1];
	if (is_end)
		data->map->end_room = &data->map->rooms[data->map->nb_rooms - 1];
}
