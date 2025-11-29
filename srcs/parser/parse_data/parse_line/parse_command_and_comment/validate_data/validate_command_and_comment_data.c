#include "lem_in.h"

inline	bool	is_end_cmd(char	*line, size_t	i)
{
	if (line[i] != 'e' || line[i + 1] != 'n' || line[i + 2] != 'd')
		return (false);
	i+= 3;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

inline	bool	is_start_cmd(char	*line, size_t	i)
{
	if (line[i] != 's' || line[i + 1] != 't' || line[i + 2] != 'a'
		||line[i + 3] != 'r' || line[i + 4] != 't')
		return (false);
	i += 5;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

//is valid_cmd