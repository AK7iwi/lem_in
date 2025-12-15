#include "lem_in.h"

static	bool	bfs(t_map *map, bool *visited, t_room	**queue, size_t queue_front, size_t queue_back)
{
	t_room	*current;
	t_link	*link;
	size_t	neighbor_idx;

	while (queue_front < queue_back)
	{
		current = queue[queue_front++];
		
		if (current == map->end_room)
			return (0);

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

	return (1);
}

static	bool	init_bfs(t_map *map, bool **visited, t_room ***queue, size_t *queue_front, size_t *queue_back)
{
	*visited = malloc(sizeof(bool) * map->nb_rooms);
	if (!*visited)
		return (1);
	for (size_t i = 0; i < map->nb_rooms; i++)
		(*visited)[i] = false;

	*queue = malloc(sizeof(t_room *) * map->nb_rooms);
	if (!*queue)
		return (free_bfs_arrays(*visited, NULL), 1);

	*queue_front = 0;
	*queue_back = 0;
	(*queue)[(*queue_back)++] = map->start_room;
	(*visited)[get_room_index(map, map->start_room)] = true;

	return (0);
}

bool	has_path(t_data *data)
{
	bool	*visited;
	t_room	**queue;
	size_t	queue_front, queue_back;

	if (init_bfs(data->map, &visited, &queue, &queue_front, &queue_back))
		return (data->err.gen_errors |= E_MEMORY, false);
	if (bfs(data->map, visited, queue, queue_front, queue_back))
		return (free_bfs_arrays(visited, queue), false);

	return (free_bfs_arrays(visited, queue), true);
}
