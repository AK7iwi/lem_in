#include "lem_in.h"

static	inline	bool	is_dash(char c)
{
	return (c == '-');
}

bool	validate_link_format(char *line, size_t *room1_start, size_t *room1_end, size_t *room2_start, size_t *room2_end)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (validate_name(line, &i, room1_start, room1_end))
		return (1);
	skip_space(line, &i);
	if (!is_dash(line[i]))
		return (1);
	i++;
	skip_space(line, &i);
	if (validate_name(line, &i, room2_start, room2_end))
		return (1);
	skip_space(line, &i);
	if (!is_last_char(line[i])) // in return 
		return (1);

	return (0);
}
