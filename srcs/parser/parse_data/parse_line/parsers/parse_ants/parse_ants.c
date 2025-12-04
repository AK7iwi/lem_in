#include "lem_in.h"

bool	parse_ants(t_data	*data, char	*line)
{
	uint32_t	nb_ants;

	if (data->map->nb_rooms)
		return (EXIT_FAILURE); // error: rooms already parsed
	
	if (validate_ants(data, line, &nb_ants))
		return (EXIT_FAILURE);

	if (create_ants(data, nb_ants))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
