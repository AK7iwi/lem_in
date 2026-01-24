#include "lem_in.h"

static	bool	add_room_to_map(t_data *data, t_room *new_room)
{
	t_room	*new_rooms;
	bool	has_start, has_end;
	size_t	new_capacity;
	size_t	start_index = 0, end_index = 0;

	if (data->map->nb_rooms >= data->map->capacity)
	{
		// Save the boolean value before free
		has_start = (data->map->start_room != NULL);
		has_end = (data->map->end_room != NULL);
		if (has_start)
			start_index = data->map->start_room - data->map->rooms;
		if (has_end)
			end_index = data->map->end_room - data->map->rooms;

		if (data->map->capacity == 0)
			new_capacity = 1;
		else
			new_capacity = data->map->capacity * 2;

		new_rooms = malloc(sizeof(t_room) * new_capacity);
		if (!new_rooms)
		{
			data->err.gen_errors |= E_MEMORY;
			return (1);
		}

		for (size_t i = 0; i < data->map->nb_rooms; i++)
			new_rooms[i] = data->map->rooms[i];

		if (data->map->rooms)
			free(data->map->rooms);

		data->map->rooms = new_rooms;
		data->map->capacity = new_capacity;

		if (has_start)
			data->map->start_room = &data->map->rooms[start_index]; 
		if (has_end)
			data->map->end_room = &data->map->rooms[end_index];
	}
	data->map->rooms[data->map->nb_rooms] = *new_room;
	
	return (0);
}

bool	create_room(t_data *data, char *name,
					uint32_t x, uint32_t y,
					bool is_start, bool is_end)
{
	t_room	new_room;
	
	new_room.name = name;
	new_room.x = x;
	new_room.y = y;
	new_room.is_empty = true;
	new_room.link = NULL;
	
	if (add_room_to_map(data, &new_room))
	{
		free(new_room.name);
		return (1);
	}
	data->map->nb_rooms++;

	if (is_start)
		data->map->start_room = &data->map->rooms[data->map->nb_rooms - 1];
	if (is_end)
		data->map->end_room = &data->map->rooms[data->map->nb_rooms - 1];

	return (0);
}
