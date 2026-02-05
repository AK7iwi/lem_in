#include "lem_in.h"

void	reset_bfs_arrays(t_map *map, bool *visited, t_room **parent, size_t *queue_front, size_t *queue_back)
{
	for (size_t i = 0; i < map->nb_rooms; i++)
		visited[i] = false;

	for (size_t i = 0; i < map->nb_rooms; i++)
		parent[i] = NULL;

	*queue_front = 0;
	*queue_back = 1;
	visited[get_room_index(map, map->start_room)] = true;
	parent[get_room_index(map, map->start_room)] = map->start_room;
}
