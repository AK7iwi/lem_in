#include "lem_in.h"

bool	is_valid_name(char *line, size_t *i)
{
	size_t	j = (*i);

	if (line[*i] == 'L' || line[*i] == '#') //# already check bottom with isalnum
		return (false);
	while (is_alnum(line[*i]))
		(*i)++;
	return (j < (*i));
}

bool	is_valid_number(char *line, size_t *i)
{
	size_t	j = (*i);

	while (is_digit(line[*i]))
		(*i)++;
	return (j < (*i));
}
