#include "lem_in.h"

char	*extract_name(t_data *data, char *line, size_t name_start, size_t name_end)
{
	size_t	name_len;
	char	*name;

	name_len = name_end - name_start;
	name = malloc(sizeof(char) * (name_len + 1));
	if (!name)
		return (data->err.gen_errors |= E_MEMORY, NULL);
	
	for (size_t j = 0; j < name_len; j++)
		name[j] = line[name_start + j];
	name[name_len] = '\0';
	
	return (name);
}
