#include "lem_in.h"

static	uint32_t	extract_coordinate(char *line, size_t start, size_t end)
{
	uint32_t	result;

	result = 0;
	while (start < end)
	{
		result = result * 10 + (line[start] - '0');
		start++;
	}
	return (result);
}

char	*extract_name(char *line, size_t name_start, size_t name_end)
{
	size_t	name_len;
	char	*name;

	name_len = name_end - name_start;
	name = malloc(sizeof(char) * (name_len + 1));
	if (!name)
		return (NULL); // memory error 
	
	for (size_t j = 0; j < name_len; j++)
		name[j] = line[name_start + j];
	name[name_len] = '\0';
	
	return (name);
}

bool	extract_room(t_data *data, char *line,
						char **name, uint32_t *x, uint32_t *y,
						size_t name_start, size_t name_end,
						size_t x_start, size_t x_end,
						size_t y_start, size_t y_end)
{
	(void)data;
	*name = extract_name(line, name_start, name_end);
	if (!(*name))
		return (1);
	*x = extract_coordinate(line, x_start, x_end);
	*y = extract_coordinate(line, y_start, y_end);

	return (0);
}
