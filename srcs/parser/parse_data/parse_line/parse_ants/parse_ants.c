#include "lem_in.h"

bool	parse_nb_ants_line(t_data *data, char	*line)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	init_nb_ants(data, line);
	return (EXIT_SUCCESS);
}
