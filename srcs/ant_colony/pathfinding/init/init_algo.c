#include "lem_in.h"

static	bool	init_dinic(t_map *map, bool **used_rooms)
{
	*used_rooms = malloc(sizeof(bool) * map->nb_rooms);
	if (!*used_rooms)
		return (1);
	for (size_t i = 0; i < map->nb_rooms; i++)
		(*used_rooms)[i] = false;

	return (0);
}

static	bool	init_bfs(t_map *map, t_room ***queue, bool **visited, t_room ***parent, size_t *queue_front, size_t *queue_back)
{
	*queue = malloc(sizeof(t_room *) * map->nb_rooms);
	if (!*queue)
		return (1);

	*visited = malloc(sizeof(bool) * map->nb_rooms);
	if (!*visited)
	{
		free_arrays(*queue, NULL, NULL, NULL);
		return (1);
	}
	for (size_t i = 0; i < map->nb_rooms; i++)
		(*visited)[i] = false;

	*parent = malloc(sizeof(t_room *) * map->nb_rooms);
	if (!*parent)
	{
		free_arrays(*queue, *visited, NULL, NULL);
		return (1);
	}
	for (size_t i = 0; i < map->nb_rooms; i++)
		(*parent)[i] = NULL;

	*queue_front = 0;
	*queue_back = 0;
	(*queue)[(*queue_back)++] = map->start_room;
	(*visited)[get_room_index(map, map->start_room)] = true;
	(*parent)[get_room_index(map, map->start_room)] = map->start_room;

	return (0);
}

bool	init_algo(t_map *map, t_room ***queue, bool **visited, t_room ***parent, bool **used_rooms, size_t *queue_front, size_t *queue_back)
{
	if (init_bfs(map, queue, visited, parent, queue_front, queue_back))
		return (1);
	if (init_dinic(map, used_rooms))
	{
		free_arrays(*queue, *visited, *parent, NULL);
		return (1);
	}

	return (0);
}
