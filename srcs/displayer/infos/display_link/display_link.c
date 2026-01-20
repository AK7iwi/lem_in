#include "lem_in.h"

static	void	display_link(t_room *room1, t_room *room2)
{
	ft_putstr(room1->name, STDOUT_FILENO);
	ft_putchar('-', STDOUT_FILENO);
	ft_putstr(room2->name, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

void	display_links(t_map *map)
{
	size_t	i = 0;
	t_link	*current_link;
	t_room	*room1;
	t_room	*room2;

	while (i < map->nb_rooms)
	{
		room1 = &map->rooms[i];
		current_link = room1->link;
		while (current_link)
		{
			room2 = current_link->room;
			if (room2 > room1)
				display_link(room1, room2);
			current_link = current_link->next;
		}
		i++;
	}
}
