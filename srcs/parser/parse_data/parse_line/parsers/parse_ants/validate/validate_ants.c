#include "lem_in.h"

bool	validate_ants(t_data *data, char *line, uint32_t *nb_ants)
{
	(void)data;
	if (validate_ants_format(line))
		return (1); // error 
	*nb_ants = ft_atoi(line); //extract
	if (validate_ants_value(*nb_ants))
		return (1); //error: nb_ants between 1 and 65000?

	return (0);
}
