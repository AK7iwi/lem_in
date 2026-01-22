#include "lem_in.h"

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long long	j;
	int			count;

	i = 0;
	j = 0;
	count = 1;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			count *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (j * count > 2147483647)
			return (-1);
		else if (j * count < -2147483648)
			return (0);
		j = j * 10 + nptr[i] - '0';
		i++;
	}
	return (j * count);
}
