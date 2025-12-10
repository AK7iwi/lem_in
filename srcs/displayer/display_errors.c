#include "lem_in.h"

static	void	display_parsing_errors(uint16_t parsing_errors)
{
	if (parsing_errors & E_ARGC)
		ft_putstr(ERR_ARGC, STDERR_FILENO);

	if (parsing_errors & E_EMPTY_FILE)
		ft_putstr(ERR_EMPTY_FILE, STDERR_FILENO);

	if (parsing_errors & E_EMPTY_LINE)
		ft_putstr(ERR_EMPTY_LINE, STDERR_FILENO);
	if (parsing_errors & E_NUMBER)
		ft_putstr(ERR_NUMBER, STDERR_FILENO);
}

static	void	display_gen_errors(uint8_t gen_errors)
{
	if (gen_errors & E_MEMORY)
		ft_putstr(ERR_MEMORY, STDERR_FILENO);
	if (gen_errors & E_TEST)
		ft_putstr(ERR_TEST, STDERR_FILENO);
}

void	display_errors(t_err error)
{
	ft_putstr(COLOR_RED "ERROR" COLOR_RESET "\n", STDERR_FILENO);
	if (error.line_error)
	{
		ft_putstr("Line ", STDERR_FILENO);
		ft_putnbr(error.line_error, STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
	}
	if (error.gen_errors)
		display_gen_errors(error.gen_errors);
	if (error.parsing_errors)
		display_parsing_errors(error.parsing_errors);
}
