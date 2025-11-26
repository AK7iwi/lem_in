#include "lem_in.h"

static	bool	add_room_to_map(t_data *data, t_room *new_room)
{
	t_room	*new_rooms;
	size_t	new_size;

	new_size = data->map->nb_rooms + 1;
	new_rooms = malloc(sizeof(t_room) * new_size);
	if (!new_rooms)
		return (EXIT_FAILURE); //memory error
	
	for (size_t i = 0; i < data->map->nb_rooms; i++)
		new_rooms[i] = data->map->rooms[i];
	
	new_rooms[data->map->nb_rooms] = *new_room;
	
	free(data->map->rooms);
	data->map->rooms = new_rooms;
	data->map->nb_rooms = new_size;
	
	return (EXIT_SUCCESS);
}

static	uint16_t	extract_coordinate(char *line, size_t start, size_t end)
{
	uint16_t	result;

	result = 0;
	while (start < end)
	{
		result = result * 10 + (line[start] - '0');
		start++;
	}
	return (result);
}

static	char	*extract_room_name(char	*line, size_t	name_start, size_t	name_end)
{
	size_t	name_len;
	char	*name;

	name_len = name_end - name_start;
	name = malloc(sizeof(char) * (name_len + 1));
	if (!name)
		return (NULL); // memory error 
	
	for (size_t j = 0; j < name_len; j++)
		name[j] = line[name_start + j];
	name[name_len] = '\0';
	
	return (name);
}

bool	init_room(t_data *data, char *line,
					size_t name_start, size_t name_end,
					size_t x_start, size_t x_end,
					size_t y_start, size_t y_end,
					bool is_start, bool is_end)
{
	t_room	new_room;
	
	new_room.name = extract_room_name(line, name_start, name_end);
	if (!new_room.name)
		return (EXIT_FAILURE);
	
	new_room.x = extract_coordinate(line, x_start, x_end);
	new_room.y = extract_coordinate(line, y_start, y_end);
	
	new_room.is_empty = true;
	new_room.is_start = is_start;
	new_room.is_end = is_end;
	new_room.link = NULL;
	
	if (add_room_to_map(data, &new_room))
		return (free(new_room.name), EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
