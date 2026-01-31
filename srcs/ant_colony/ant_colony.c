#include "lem_in.h"

bool    ant_colony(t_data *data)
{
    return (explore() || routing());
}
