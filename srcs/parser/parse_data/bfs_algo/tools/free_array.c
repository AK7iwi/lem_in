#include "lem_in.h"

void	free_bfs_arrays(bool	*visited, t_room	**queue)
{
	if (visited)
		free(visited);
	if (queue)
		free(queue);
}