#include "lem_in.h"

static void	print_links(t_map *map)
{
	size_t		i;
	t_link	*current_link;
	t_room		*room1;
	t_room		*room2;

	i = 0;
	while (i < map->nb_rooms)
	{
		room1 = &map->rooms[i];
		current_link = room1->link;
		
		while (current_link)
		{
			room2 = current_link->room;

			if (room2 > room1)
			{
				ft_putstr(room1->name, STDOUT_FILENO);
				ft_putchar('-', STDOUT_FILENO);
				ft_putstr(room2->name, STDOUT_FILENO);
				ft_putchar('\n', STDOUT_FILENO);
			}
			current_link = current_link->next;
		}
		i++;
	}
}

static void	print_room(t_room *room)
{
	ft_putstr(room->name, STDOUT_FILENO);
	ft_putchar(' ', STDOUT_FILENO);
	ft_putnbr(room->x, STDOUT_FILENO);
	ft_putchar(' ', STDOUT_FILENO);
	ft_putnbr(room->y, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

static void	print_rooms(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_rooms)
	{
		if (&map->rooms[i] == map->start_room || &map->rooms[i] == map->end_room)
		{
			i++;
			continue;
		}
		print_room(&map->rooms[i]);
		i++;
	}
}

void	display_infos(t_data *data)
{
	t_room	*start_room;
	t_room	*end_room;

	ft_putnbr(data->nb_ants, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
	
	start_room = data->map->start_room;
	ft_putstr("##start\n", STDOUT_FILENO);
	print_room(start_room);
	
	end_room = data->map->end_room;
	ft_putstr("##end\n", STDOUT_FILENO);
	print_room(end_room);

	print_rooms(data->map);
	print_links(data->map);
}
