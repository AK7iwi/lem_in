#include "lem_in.h"

void	free_arrays(t_room **queue, bool *visited, t_room **parent, bool *used_rooms)
{
	if (queue)
		free(queue);
	if (visited)
		free(visited);
	if (parent)
		free(parent);
	if (used_rooms)
		free(used_rooms);
}
