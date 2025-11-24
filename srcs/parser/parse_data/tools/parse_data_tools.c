#include "lem_in.h"

// bool	is_existing_room()
// {

// }

inline	bool	is_end_room(char	*line, size_t	*i)
{
	return (line[*i] == 'e' && line[*i + 1] == 'n' && line[*i + 2] == 'd');
}

inline	bool	is_start_room(char	*line, size_t	*i)
{
	return (line[*i] == 's' && line[*i + 1] == 't' && line[*i + 2] == 'a'
			&& line[*i + 3] == 'r' && line[*i + 4] == 't');
}

bool	is_valid_name(char	*line, size_t	*i)
{
	if (line[*i] == 'L' || line[*i] == '#')
		return (false);
	while (line[*i] && line[*i] != ' ')
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
	while (line[*i] && line[*i] != ' ' && !is_last_char(line[*i]))
	{
		if (!is_digit(line[*i]))
			return (false);
		found_digit = true;
		(*i)++;
	}
	return (found_digit);
}

//tools
void	skip_space(char	*line, size_t	*i)
{
	while (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
}
