#include "lem_in.h"

static void	free_room_links(t_link *link)
{
	t_link	*current;
	t_link	*next;

	current = link;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

static void	free_rooms(t_map *map)
{
	size_t	i = 0;

	if (!map->rooms)
		return;

	while (i < map->nb_rooms)
	{
		if (map->rooms[i].name)
			free(map->rooms[i].name);
		if (map->rooms[i].link)
			free_room_links(map->rooms[i].link);
		i++;
	}
	free(map->rooms);
}

static void	free_ants(t_ant *ant)
{
	t_ant	*current;
	t_ant	*next;

	current = ant;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return;
	
	if (data->ant)
	{
		free_ants(data->ant);
		data->ant = NULL;
	}
	if (data->map)
	{
		free_rooms(data->map);
		free(data->map);
		data->map = NULL;
	}
	if (data->norm)
	{
		free(data->norm);
		data->norm = NULL;
	}
}
