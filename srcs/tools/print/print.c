#include "lem_in.h"

static	void	ft_putchar(char	c, int	fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int	n, int	fd)
{
	long long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar('-', fd);
		b *= -1;
	}
	if (b <= 9)
		ft_putchar('0' + b, fd);
	else if (b > 9)
	{
		ft_putnbr(b / 10, fd);
		ft_putchar('0' + b % 10, fd);
	}
}

void	ft_putstr(char *str, int	fd)
{
	while (*str)
	{
		ft_putchar(*str, fd);
		str++;
	}
}
