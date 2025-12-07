#include "lem_in.h"

inline	bool	is_alnum(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| is_digit(c));
}

inline	bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
