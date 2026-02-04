#include "lem_in.h"

static	inline	size_t	get_room_index(t_map *map, t_room *room)
{
	return (room - map->rooms);
}

bool	bfs(t_map *map, bool *visited, t_room **queue, size_t queue_front, size_t queue_back)
{
	t_room	*current;
	t_link	*link;
	size_t	neighbor_idx;

	while (queue_front < queue_back)
	{
		//not at good place, should be in the loop, the start room can't equal the end
		current = queue[queue_front++];
		if (current == map->end_room)
			return (0);

		link = current->link;
		while (link)
		{
			neighbor_idx = get_room_index(map, link->room);
			if (!visited[neighbor_idx])
			{
				//if (link->room == map->end_room)
				//return (0)
				//else 
				queue[queue_back++] = link->room;
				visited[neighbor_idx] = true;
			}
			link = link->next;
		}
	}

	return (1);
}

//init_bfs_array
bool	init_bfs(t_map *map, bool **visited, t_room ***queue, size_t *queue_front, size_t *queue_back)
{
	*visited = malloc(sizeof(bool) * map->nb_rooms);
	if (!*visited)
		return (1);
	for (size_t i = 0; i < map->nb_rooms; i++)
		(*visited)[i] = false;

	*queue = malloc(sizeof(t_room *) * map->nb_rooms);
	if (!*queue)
	{
		free_bfs_arrays(*visited, NULL);
		return (1);
	}

	//in bfs 
	*queue_front = 0;
	*queue_back = 0;
	(*queue)[(*queue_back)++] = map->start_room;
	(*visited)[get_room_index(map, map->start_room)] = true;

	return (0);
}

// bool	has_path(t_data *data)
// {
// 	bool	*visited;
// 	t_room	**queue;
// 	size_t	queue_front, queue_back;

// 	if (init_bfs(data->map, &visited, &queue, &queue_front, &queue_back))
// 	{
// 		data->err.gen_errors |= E_MEMORY;
// 		return (false);
// 	}
// 	if (bfs(data->map, visited, queue, queue_front, queue_back))
// 	{
// 		free_bfs_arrays(visited, queue);
// 		return (false);
// 	}
// 	free_bfs_arrays(visited, queue);

// 	return (true);
// }
