#include "lem_in.h"

void	set_ants_start_room(t_data	*data)
{
	t_ant	*current;

	current = data->ant;
	while (current)
	{
		current->current_room = data->map->start_room;
		current = current->next;
	}
}

bool	create_ants(t_data	*data, uint32_t	nb_ants)
{
	t_ant		*new_ant, *prev_ant;
	uint32_t	i;

	data->nb_ants = nb_ants;
	data->ant = NULL;
	prev_ant = NULL;
	i = 1;
	while (i <= data->nb_ants)
	{
		new_ant = malloc(sizeof(t_ant));
		if (!new_ant)
			return (1); // memory error
		new_ant->id = i;
		new_ant->current_room = NULL;
		new_ant->has_moved = false;
		new_ant->next = NULL;
		
		if (prev_ant)
			prev_ant->next = new_ant;
		else
			data->ant = new_ant;
		
		prev_ant = new_ant;
		i++;
	}
	return (0);
}
