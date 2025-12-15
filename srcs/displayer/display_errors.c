#include "lem_in.h"

static	void	display_parsing_errors(uint32_t parsing_errors)
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
	if (parsing_errors & E_ANTS_AND_ROOMS_MIXED)
		ft_putstr(ERR_ANTS_AND_ROOMS_MIXED, STDERR_FILENO);
	if (parsing_errors & E_ROOM_EXISTS)
		ft_putstr(ERR_ROOM_EXISTS, STDERR_FILENO);
	if (parsing_errors & E_COORDS_VALUES)
		ft_putstr(ERR_COORDS_VALUES, STDERR_FILENO);
	if (parsing_errors & E_COORDS_EXIST)
		ft_putstr(ERR_COORDS_EXIST, STDERR_FILENO);
	if (parsing_errors & E_NB_ROOMS)
		ft_putstr(ERR_NB_ROOMS, STDERR_FILENO);

	/* Link errors */
	if (parsing_errors & E_ANTS_AND_LINKS_MIXED)
		ft_putstr(ERR_ANTS_AND_LINKS_MIXED, STDERR_FILENO);
	if (parsing_errors & E_ROOMS_AND_LINKS_MIXED)
		ft_putstr(ERR_ROOMS_AND_LINKS_MIXED, STDERR_FILENO);
	if (parsing_errors & E_ROOM_NOT_FOUND)
		ft_putstr(ERR_ROOM_NOT_FOUND, STDERR_FILENO);
	if (parsing_errors & E_LINK_EXISTS)
		ft_putstr(ERR_LINK_EXISTS, STDERR_FILENO);
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
