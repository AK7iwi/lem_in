#include "lem_in.h"

bool	validate_ants_format(char *line)
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
