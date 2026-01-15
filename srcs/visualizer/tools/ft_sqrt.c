#include "lem_in.h"

float	ft_sqrt(float n)
{
	float	x, prev, epsilon;

	x = n;
	epsilon = 0.00001f;
	while (true)
	{
		prev = x;
		x = (x + n / x) / 2;
		if (x - prev < epsilon && prev - x < epsilon)
			break ;
	}

	return (x);
}