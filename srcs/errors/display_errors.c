#include "lem_in.h"

static	void	display_parsing_errors(uint16_t parsing_errors)
{
	if (parsing_errors & E_ARGC)
		ft_putstr(ERR_ARGC, STDERR_FILENO);
	if (parsing_errors & E_EMPTY_LINE)
		ft_putstr(ERR_EMPTY_LINE, STDERR_FILENO);
	if (parsing_errors & E_NUMBER)
		ft_putstr(ERR_NUMBER, STDERR_FILENO);
}

static	void	display_gen_errors(uint8_t gen_errors)
{
	(void)gen_errors;
	printf("display_gen_errors\n");
}

void	errors_displayer(t_err error)
{
	ft_putstr("ERROR:\n", STDERR_FILENO);
	if (error.gen_errors)
		display_gen_errors(error.gen_errors);
	if (error.parsing_errors)
		display_parsing_errors(error.parsing_errors);
}
