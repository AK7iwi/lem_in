#include "lem_in.h"

static	void	display_end_room(t_data *data)
{
	ft_putstr("##end\n", STDOUT_FILENO);
	display_room(data->map->end_room);
}

static	void	display_start_room(t_data *data)
{
	ft_putstr("##start\n", STDOUT_FILENO);
	display_room(data->map->start_room);
}

static	void	display_nb_ants(t_data *data)
{
	ft_putnbr(data->nb_ants, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

void	display_infos(t_data *data)
{
	display_nb_ants(data);
	display_start_room(data);
	display_end_room(data);
	display_rooms(data->map);
	display_links(data->map);
}
