#include "lem_in.h"

bool	validate_ants(t_data *data, char *line, uint32_t *nb_ants)
{
	if (validate_ants_format(line))
		return (1);
	extract_nb_ants(line, nb_ants);
	if (validate_ants_value(*nb_ants))
		return (data->err.parsing_errors |= E_ANTS_VALUE, 1);

	return (0);
}
