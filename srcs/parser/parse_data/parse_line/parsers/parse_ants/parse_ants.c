#include "lem_in.h"

bool	parse_ants(t_data *data, char *line)
{
	uint32_t	nb_ants;

	if (data->map->nb_rooms || data->map->nb_links)
		return (1);
	
	if (validate_ants(data, line, &nb_ants))
		return (1);
	if (create_ants(data, nb_ants))
		return (1);

	return (0);
}
