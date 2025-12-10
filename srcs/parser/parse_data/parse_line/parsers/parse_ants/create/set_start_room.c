#include "lem_in.h"

void	set_start_room(t_data	*data)
{
	t_ant	*current;

	current = data->ant;
	while (current)
	{
		current->current_room = data->map->start_room;
		current = current->next;
	}
}