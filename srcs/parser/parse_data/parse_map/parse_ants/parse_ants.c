#include "lem_in.h"

bool	parse_ants(t_data *data, char *line)
{
	uint16_t	nb_ants;

	return ((data->map->nb_rooms || data->map->nb_links) 
		  || validate_ants(&data->err, line, &nb_ants)
		  || create_ants(data, nb_ants));
}
