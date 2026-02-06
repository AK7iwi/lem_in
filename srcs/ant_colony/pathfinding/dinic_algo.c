#include "lem_in.h"

bool	dinic(t_data *data, t_pathset *pathset)
{
	t_room	    **queue, **parent;
	bool	    *visited, *used_rooms;
	size_t	    queue_front, queue_back;

	if (init_algo(data->map, &queue, &visited, &parent, &used_rooms, &queue_front, &queue_back))
	{
		data->err.gen_errors |= E_MEMORY;
		return (1);
	}
	
	while (!bfs(data->map, visited, used_rooms, parent, queue, queue_front, queue_back))
	{
		if (store_path(data, parent, used_rooms, pathset, pathset->nb_paths))
		{
			free_arrays(queue, visited, parent, used_rooms);
			return (1);
		}
		pathset->nb_paths++;
		reset_bfs_arrays(data->map, visited, parent, queue, &queue_front, &queue_back);
	}
	free_arrays(queue, visited, parent, used_rooms);

	if (!pathset->nb_paths)
	{
		data->err.gen_errors |= E_NO_PATH;
		return (1);	
	}

	return (0);
}
