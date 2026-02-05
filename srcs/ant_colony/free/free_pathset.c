#include "lem_in.h"

void	free_pathset(t_pathset *pathset)
{
	if (pathset->paths)
	{
		for (uint16_t i = 0; i < pathset->nb_paths; i++)
		{
			if (pathset->paths[i].rooms)
				free(pathset->paths[i].rooms);
		}
		free(pathset->paths);
	}

	pathset->paths = NULL;
	pathset->nb_paths = 0;
}
