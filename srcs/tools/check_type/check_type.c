#include "lem_in.h"

inline	bool	is_last_char(char c)
{
	return (c == '\0' || c == '\n');
}

inline	bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

inline	bool	is_alnum(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
