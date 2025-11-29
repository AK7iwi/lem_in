#include "lem_in.h"

void	skip_space(char	*line, size_t	*i)
{
	while (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
}
