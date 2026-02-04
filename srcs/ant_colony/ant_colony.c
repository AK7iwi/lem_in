#include "lem_in.h"

bool    ant_colony(t_data *data)
{
    t_pathset pathset;

    init_pathset(&pathset);

    return (!dinic(data, &pathset)); // || routing() //returrn no path error 
}
