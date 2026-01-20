#include "lem_in.h"

void	display_gen_error(uint8_t gen_errors)
{
	if (gen_errors & E_MEMORY)
		ft_putstr(ERR_MEMORY, STDERR_FILENO);
}