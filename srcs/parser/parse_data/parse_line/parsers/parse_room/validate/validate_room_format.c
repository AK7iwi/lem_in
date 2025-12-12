#include "lem_in.h"

static	bool	validate_coordinate(char *line, size_t *i, size_t *coord_start, size_t *coord_end)
{
	(*coord_start) = *i;
	if (!is_valid_number(line, i))
		return (1);
	(*coord_end) = *i;

	return (0);
}

bool	validate_room_format(t_data *data, char *line,
								size_t *name_start, size_t *name_end,
								size_t *x_start, size_t *x_end,
								size_t *y_start, size_t *y_end)
{
	size_t	i = 0;
	(void)data;
	skip_space(line, &i);
	if (validate_name(line, &i, name_start, name_end))
		return (1);
	skip_space(line, &i);
	if (validate_coordinate(line, &i, x_start, x_end))
		return (1);
	skip_space(line, &i);
	if (validate_coordinate(line, &i, y_start, y_end))
		return (1);
	skip_space(line, &i);
	if (!is_last_char(line[i]))
		return (1);

	return (0);
}
