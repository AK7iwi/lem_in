#include "lem_in.h"

static size_t	get_room_index(t_map *map, t_room *room)
{
	return (room - map->rooms);
}

//init_bfs, bfs
static	bool    bfs(t_map	*map)
{
	bool    	*visited;
	t_room		**queue;
	size_t		queue_front, queue_back;
	t_room		*current;
	t_room_link	*link;
	size_t		neighbor_idx;

	if (map->start_room == map->end_room)
		return (true);

	visited = malloc(sizeof(bool) * map->nb_rooms);
	if (!visited)
		return (false);
	for (size_t i = 0; i < map->nb_rooms; i++)
		visited[i] = false;

	queue = malloc(sizeof(t_room *) * map->nb_rooms);
	if (!queue)
		return (free(visited), false);

	queue_front = 0;
	queue_back = 0;
	queue[queue_back++] = map->start_room;
	visited[get_room_index(map, map->start_room)] = true;

	while (queue_front < queue_back)
	{
		current = queue[queue_front++];
		
		if (current == map->end_room)
		{
			free(visited);
			free(queue);
			return (true);
		}

		link = current->link;
		while (link)
		{
			neighbor_idx = get_room_index(map, link->room);
			if (!visited[neighbor_idx])
			{
				visited[neighbor_idx] = true;
				queue[queue_back++] = link->room;
			}
			link = link->next;
		}
	}

	free(visited);
	free(queue); //good free?
	return (false);
}


bool    has_path(t_map	*map)
{
	return (bfs(map));
}