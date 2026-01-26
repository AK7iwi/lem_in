#include "lem_in.h"

static	void	display_end_room(t_room *end_room)
{
	ft_putstr("##end\n", STDOUT_FILENO);
	display_room(end_room);
}

static	void	display_start_room(t_room *start_room)
{
	ft_putstr("##start\n", STDOUT_FILENO);
	display_room(start_room);
}

static	void	display_nb_ants(uint16_t nb_ants)
{
	ft_putnbr(nb_ants, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

void	display_infos(t_data *data)
{
	display_nb_ants(data->nb_ants);
	display_start_room(data->map->start_room);
	display_end_room(data->map->end_room);
	display_rooms(data->map);
	display_links(data->map);
}
