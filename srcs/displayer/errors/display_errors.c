#include "lem_in.h"

static	void	display_error_header(size_t line_error)
{
	ft_putstr(COLOR_RED "ERROR" COLOR_RESET "\n", STDERR_FILENO);
	if (line_error)
	{
		ft_putstr("Line ", STDERR_FILENO);
		ft_putnbr(line_error, STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
	}
}

void	display_errors(t_err error)
{
	display_error_header(error.line_error);
	if (error.visu_errors)
		display_visu_error(error.visu_errors);
	else if (error.gen_errors)
		display_gen_error(error.gen_errors);
	else if (error.parsing_errors)
		display_parsing_error(error.parsing_errors);
	else
		display_format_error();
}
