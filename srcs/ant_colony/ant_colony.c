#include "lem_in.h"

bool    ant_colony(t_data *data)
{
    t_pathset pathset;


    //maybe init after 
    if (init_pathset(data, &pathset))
        return (1);

    if (dinic(data, &pathset))
        return (1);

    // routing(data, &pathset)

    return (0);
}
