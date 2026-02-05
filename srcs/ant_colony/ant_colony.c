#include "lem_in.h"


static  void	display_paths(t_pathset *pathset)
{
	ft_putstr("\n=== PATHS FOUND ===\n", STDOUT_FILENO);
	ft_putstr("Number of paths: ", STDOUT_FILENO);
	ft_putnbr(pathset->nb_paths, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);

	for (uint16_t i = 0; i < pathset->nb_paths; i++)
	{
		ft_putstr("\nPath ", STDOUT_FILENO);
		ft_putnbr(i + 1, STDOUT_FILENO);
		ft_putstr(" (length: ", STDOUT_FILENO);
		ft_putnbr(pathset->paths[i].len, STDOUT_FILENO);
		ft_putstr(" rooms, steps: ", STDOUT_FILENO);
		ft_putnbr(pathset->paths[i].len - 1, STDOUT_FILENO);
		ft_putstr("):\n  ", STDOUT_FILENO);

		for (uint16_t j = 0; j < pathset->paths[i].len; j++)
		{
			ft_putstr(pathset->paths[i].rooms[j]->name, STDOUT_FILENO);
			if (j < pathset->paths[i].len - 1)
				ft_putstr(" -> ", STDOUT_FILENO);
		}
		ft_putchar('\n', STDOUT_FILENO);
	}
	ft_putstr("===================\n\n", STDOUT_FILENO);
}

bool    ant_colony(t_data *data)
{
    t_pathset pathset;


    //maybe init after 
    if (init_pathset(data, &pathset))
        return (1);

    if (dinic(data, &pathset))
    {
        free_pathset(&pathset);
        return (1);
    }
    // routing(data, &pathset)
    display_paths(&pathset);
    free_pathset(&pathset);

    return (0);
}
