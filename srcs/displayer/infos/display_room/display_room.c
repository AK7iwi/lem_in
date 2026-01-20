#include "lem_in.h"

void	display_room(t_room *room)
{
	ft_putstr(room->name, STDOUT_FILENO);
	ft_putchar(' ', STDOUT_FILENO);
	ft_putnbr(room->x, STDOUT_FILENO);
	ft_putchar(' ', STDOUT_FILENO);
	ft_putnbr(room->y, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

void	display_rooms(t_map *map)
{
	size_t	i = 0;

	while (i < map->nb_rooms)
	{
		if (&map->rooms[i] == map->start_room || &map->rooms[i] == map->end_room)
		{
			i++;
			continue;
		}
		display_room(&map->rooms[i]);
		i++;
	}
}
