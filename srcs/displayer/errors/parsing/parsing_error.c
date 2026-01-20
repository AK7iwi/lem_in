#include "lem_in.h"

void	display_format_error(void)
{
	ft_putstr(ERR_FORMAT, STDERR_FILENO);
}

static	void	display_path_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_NO_PATH)
		ft_putstr(ERR_NO_PATH, STDERR_FILENO);
}

static	void	display_link_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_ROOMS_AND_LINKS_MIXED)
		ft_putstr(ERR_ROOMS_AND_LINKS_MIXED, STDERR_FILENO);
	if (parsing_errors & E_ROOM_NOT_FOUND)
		ft_putstr(ERR_ROOM_NOT_FOUND, STDERR_FILENO);
	if (parsing_errors & E_SAME_ROOM)
		ft_putstr(ERR_SAME_ROOM, STDERR_FILENO);
	if (parsing_errors & E_LINK_EXISTS)
		ft_putstr(ERR_LINK_EXISTS, STDERR_FILENO);
	if (parsing_errors & E_NB_LINKS)
		ft_putstr(ERR_NB_LINKS, STDERR_FILENO);
}

static	void	display_room_error(uint32_t parsing_errors)
{
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
}

static	void	display_command_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_TWO_STARTS)
		ft_putstr(ERR_TWO_STARTS, STDERR_FILENO);
	if (parsing_errors & E_TWO_ENDS)
		ft_putstr(ERR_TWO_ENDS, STDERR_FILENO);
	if (parsing_errors & E_START)
		ft_putstr(ERR_START, STDERR_FILENO);
	if (parsing_errors & E_END)
		ft_putstr(ERR_END, STDERR_FILENO);
}

static	void	display_ants_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_ANTS_VALUE)
		ft_putstr(ERR_ANTS_VALUE, STDERR_FILENO);
}

static	void	display_empty_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_EMPTY_FILE)
		ft_putstr(ERR_EMPTY_FILE, STDERR_FILENO);
	if (parsing_errors & E_EMPTY_LINE)
		ft_putstr(ERR_EMPTY_LINE, STDERR_FILENO);
}

static	void	display_argc_error(uint32_t parsing_errors)
{
	if (parsing_errors & E_ARGC)
		ft_putstr(ERR_ARGC, STDERR_FILENO);
}

void	display_parsing_error(uint32_t parsing_errors)
{
	display_argc_error(parsing_errors);
	display_empty_error(parsing_errors);
	display_ants_error(parsing_errors);
	display_command_error(parsing_errors);
	display_room_error(parsing_errors);
	display_link_error(parsing_errors);
	display_path_error(parsing_errors);
}
