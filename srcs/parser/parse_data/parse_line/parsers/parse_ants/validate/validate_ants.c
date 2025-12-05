#include "lem_in.h"

static	inline	bool	validate_ants_value(uint32_t nb_ants)
{
	return (nb_ants < MIN_ANTS || nb_ants > MAX_ANTS);
}

static	bool	validate_ants_format(char *line)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (1);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (1);

	return (0);
}

bool	validate_ants(t_data *data, char *line, uint32_t *nb_ants)
{
	(void)data;
	if (validate_ants_format(line))
		return (1); // error 
	*nb_ants = ft_atoi(line);
	if (validate_ants_value(*nb_ants))
		return (1); //error: nb_ants between 1 and 65000?

	return (0);
}
