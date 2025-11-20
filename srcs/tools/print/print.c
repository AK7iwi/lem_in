#include "lem_in.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}
