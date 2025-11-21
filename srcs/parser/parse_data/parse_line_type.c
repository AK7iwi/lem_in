#include "lem_in.h"

bool	parse_link(char *line)
{
	size_t		i;

	i = 0;
	skip_space(line, &i);
	if (!is_valid_name(line, &i)) //is_existing room
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (line[i] != '-')
		return (EXIT_FAILURE);
	i++;
	skip_space(line, &i);
	if (!is_valid_name(line, &i)) //is_existing room
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
	if (!is_valid_name(line, &i)) /* Room's name */
		return (EXIT_FAILURE);
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

bool	parse_comment(char *line)
{
	size_t	i;

	i = 0;
	skip_space(line, &i);
	if (line[i] == '#') 
	{
		if (line[i + 1] == '#')
			//if is_start()
			//if is_end()
		else
			return (EXIT_SUCCESS);
	} 
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
