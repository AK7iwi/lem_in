#include "lem_in.h"

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
