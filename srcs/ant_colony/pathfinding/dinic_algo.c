#include "lem_in.h"

uint16_t    dinic(t_data *data, t_pathset *pathset)
{
    bool	    *visited;
	t_room	    **queue;
	size_t	    queue_front, queue_back;
    uint16_t    max_flow = 0;

    (void)pathset;
	if (init_bfs(data->map, &visited, &queue, &queue_front, &queue_back))
	{
		data->err.gen_errors |= E_MEMORY;
		return (0);
	}
	while (!bfs(data->map, visited, queue, queue_front, queue_back))
	{
        max_flow++;
		free_bfs_arrays(visited, queue);
	}
    free_bfs_arrays(visited, queue);
    printf("max_flow:%u\n", max_flow);

    return (max_flow);
}
