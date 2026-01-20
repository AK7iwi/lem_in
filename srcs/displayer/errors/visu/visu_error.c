#include "lem_in.h"

void	display_visu_error(uint8_t visu_errors)
{
	if (visu_errors & E_VISU)
	{
		ft_putstr(ERR_VISU, STDERR_FILENO);
		ft_putstr((char *)SDL_GetError(), STDERR_FILENO);
	}
}
