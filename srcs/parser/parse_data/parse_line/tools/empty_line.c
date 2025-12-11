#include "lem_in.h"

bool	is_empty_line(char *line)
{
	size_t i = 0;

	skip_space(line, &i);
	return (is_last_char(line[i]));
}
