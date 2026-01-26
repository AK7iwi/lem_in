#include "lem_in.h"

static	uint32_t	extract_coordinate(char *line, size_t start, size_t end)
{
	uint32_t	result = 0;

	while (start < end)
	{
		result = result * 10 + (line[start] - '0');
		start++;
	}

	return (result);
}

bool	extract_room_data(t_err *err, char *line, char **name,
						  uint32_t *x, uint32_t *y,
						  size_t name_start, size_t name_end, 
						  size_t x_start, size_t x_end,
						  size_t y_start, size_t y_end)
{
	*name = extract_name(err, line, name_start, name_end);
	if (!*name)
		return (1);
	*x = extract_coordinate(line, x_start, x_end);
	*y = extract_coordinate(line, y_start, y_end);

	return (0);
}
