#include "lem_in.h"

static	inline	bool	validate_ants_value(uint32_t	*nb_ants)
{
	return (*nb_ants == 0 || *nb_ants > MAX_ANTS);
}

static	bool	validate_ants_number(char	*line)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

bool	validate_ants(t_data	*data, char	*line, uint32_t	*nb_ants)
{
	(void)data;
	if (validate_ants_number(line))
		return (EXIT_FAILURE); // error 
	*nb_ants = ft_atoi(line);
	if (validate_ants_value(nb_ants))
		return (EXIT_FAILURE); //error: nb_ants between 1 and 65000?

	return (EXIT_SUCCESS);
}
