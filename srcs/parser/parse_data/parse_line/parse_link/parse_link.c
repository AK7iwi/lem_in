#include "lem_in.h"

bool	parse_link(t_data *data, char *line)
{
	size_t	i = 0;
	t_room	*room1, *room2;
	size_t	room_start, room_end;

	skip_space(line, &i);
	room_start = i;
	if (!is_valid_name(line, &i))
		return (EXIT_FAILURE);
	room_end = i;
	room1 = is_existing_room(data, line, room_start, room_end);
	if (!room1)
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (line[i] != '-')
		return (EXIT_FAILURE);
	i++;
	skip_space(line, &i);
	room_start = i;
	if (!is_valid_name(line, &i))
		return (EXIT_FAILURE);
	room_end = i;
	room2 = is_existing_room(data, line, room_start, room_end);
	if (!room2)
		return (EXIT_FAILURE);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);
	if (is_existing_link(room1, room2) || init_link(room1, room2))
		return (EXIT_FAILURE);
	data->map->nb_links++;
	return(EXIT_SUCCESS);
}
