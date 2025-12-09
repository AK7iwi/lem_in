#include "lem_in.h"

inline	bool	validate_ants_value(uint32_t nb_ants)
{
	return (nb_ants < MIN_ANTS || nb_ants > MAX_ANTS);
}
