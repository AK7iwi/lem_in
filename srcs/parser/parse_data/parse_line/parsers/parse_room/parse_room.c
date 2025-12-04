#include "lem_in.h"

//bool validate_room()

bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end)
{
	size_t		i = 0;
	char		*name;
	uint32_t	x, y;
	size_t		name_start, name_end;
	size_t		x_start, x_end;
	size_t		y_start, y_end;

	if (data->map->nb_links)
		return (EXIT_FAILURE); //error: rooms and links mixed

	skip_space(line, &i);
	name_start = i;
	if (!is_valid_name(line, &i)) /* Room's name */
		return (EXIT_FAILURE);
	name_end = i;
	if (is_existing_room(data, line, name_start, name_end))
		return (EXIT_FAILURE);
	skip_space(line, &i);
	x_start = i;
	if (!is_valid_number(line, &i)) /* coord_x */
		return (EXIT_FAILURE);
	x_end = i;
	skip_space(line, &i);
	y_start = i;
	if (!is_valid_number(line, &i)) /* coord_y */
		return (EXIT_FAILURE);
	y_end = i;
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (EXIT_FAILURE);
	if (extract_room(data, line, &name, &x, &y, name_start, name_end, x_start, x_end, y_start, y_end) 
		|| is_existing_coordinates(data, x, y) //free_name if fail
		|| create_room(data, name, x, y, is_start, is_end)) //free_name if fail (check init)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
