#include "lem_in.h"

bool	bfs(t_map *map, bool *visited, bool *used_rooms, t_room **parent, t_room **queue, size_t queue_front, size_t queue_back)
{
	t_room	*current;
	t_link	*link;
	size_t	neighbor_idx;

	while (queue_front < queue_back)
	{
		current = queue[queue_front++];
		link = current->link;
		while (link)
		{
			neighbor_idx = get_room_index(map, link->room);
			if (!visited[neighbor_idx] && !used_rooms[neighbor_idx])
			{
				parent[neighbor_idx] = current;
				
				if (link->room == map->end_room)
					return (0);

				visited[neighbor_idx] = true;
				queue[queue_back++] = link->room;
			}
			link = link->next;
		}
	}

	return (1);
}
