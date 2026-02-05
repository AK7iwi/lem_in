#include "lem_in.h"

bool	init_pathset(t_data *data, t_pathset *pathset)
{
	pathset->paths = malloc(sizeof(t_path) * data->map->nb_rooms);
	if (!pathset->paths)
	{
		data->err.gen_errors |= E_MEMORY;
		return (1);
	}
	pathset->nb_paths = 0;
	
	return (0);
}
