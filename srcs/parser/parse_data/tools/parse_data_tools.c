#include "lem_in.h"


bool	is_valid_name(char	*line,	size_t	*i)
{
	while (line[*i])
	{
		if (!is_alnum(line[*i]))
			return (false);
		(*i)++;
	}
	return (true);
}

bool	is_valid_number(char	*line, size_t	*i)
{
	bool	found_digit;

	found_digit = false;
	while (is_digit(line[*i]))
	{
		found_digit = true;
		(*i)++;
	}
	return (found_digit);
}

void	skip_space(char	*line, size_t	*i)
{
	while (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
}

inline	bool	is_last_char(char c)
{
	return (c == '\0' || c == '\n');
}