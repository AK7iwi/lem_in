#include "lem_in.h"

bool	parse_link(char *line)
{
	size_t		i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (line[i] != '-')
		return (EXIT_FAILURE);
	i++;
	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);

	return(EXIT_SUCCESS);
}

bool	parse_room(char *line)
{
	size_t	i;

	i = 0;
	skip_space(line, &i);
	while (line[i] != ' ' && !(line[i] >= 9 && line[i] <= 13)) /* Room's name */
		i++;
	skip_space(line, &i);
	if (!is_valid_number(line, &i)) /* coord_x */
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_valid_number(line, &i)) /* coord_y */
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

bool	parse_nb_ants_line(t_data *data, char	*line)
{
	size_t	i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_number(line, &i))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (data->err.parsing_errors |= E_NUMBER , EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
