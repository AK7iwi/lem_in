#include "lem_in.h"

static	void	display_parsing_errors(uint16_t parsing_errors)
{
	if (parsing_errors & E_ARGC)
		ft_putstr(ERR_ARGC, STDERR_FILENO);

	if (parsing_errors & E_EMPTY_FILE)
		ft_putstr(ERR_EMPTY_FILE, STDERR_FILENO);

	if (parsing_errors & E_EMPTY_LINE)
		ft_putstr(ERR_EMPTY_LINE, STDERR_FILENO);

	/* Ants errors */
	if (parsing_errors & E_ANTS_VALUE)
		ft_putstr(ERR_ANTS_VALUE, STDERR_FILENO);

	/* Command errors */
	if (parsing_errors & E_TWO_STARTS)
		ft_putstr(ERR_TWO_STARTS, STDERR_FILENO);
	if (parsing_errors & E_TWO_ENDS)
		ft_putstr(ERR_TWO_ENDS, STDERR_FILENO);
	if (parsing_errors & E_START)
		ft_putstr(ERR_START, STDERR_FILENO);
	if (parsing_errors & E_END)
		ft_putstr(ERR_END, STDERR_FILENO);

	/* Room errors */
	if (parsing_errors & E_MIX_ANTS_AND_ROOMS)
		ft_putstr(ERR_MIX_ANTS_AND_ROOM, STDERR_FILENO);
	if (parsing_errors & E_ROOM_EXIST)
		ft_putstr(ERR_ROOM_EXIST, STDERR_FILENO);
	if (parsing_errors & E_COORD_VALUES)
		ft_putstr(ERR_COORD_VALUES, STDERR_FILENO);
	if (parsing_errors & E_COORD_EXIST)
		ft_putstr(ERR_COORD_EXIST, STDERR_FILENO);
	if (parsing_errors & E_NB_ROOMS)
		ft_putstr(ERR_NB_ROOMS, STDERR_FILENO);

	/* Link errors */
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
	else if (error.parsing_errors)
		display_parsing_errors(error.parsing_errors);
}
