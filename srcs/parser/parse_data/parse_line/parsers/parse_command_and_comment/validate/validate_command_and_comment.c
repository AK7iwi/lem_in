#include "lem_in.h"

bool	has_start_or_end_room(t_data *data, bool	is_start, bool	is_end)
{
	if (is_start && data->map->start_room)
		return (EXIT_FAILURE); //two start error
	else if (is_end && data->map->end_room)
		return (EXIT_FAILURE); //two end error

	return (EXIT_SUCCESS);
}

static	bool	is_end_cmd(char	*line, size_t	i)
{
	if (line[i] != 'e' || line[i + 1] != 'n' || line[i + 2] != 'd')
		return (false);
	i+= 3;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

static	bool	is_start_cmd(char	*line, size_t	i)
{
	if (line[i] != 's' || line[i + 1] != 't' || line[i + 2] != 'a'
		||line[i + 3] != 'r' || line[i + 4] != 't')
		return (false);
	i += 5;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

void	is_valid_cmd(char	*line, size_t	i, bool	*is_start, bool	*is_end)
{
	(*is_start) = false;
	(*is_end) = false;

	if (is_start_cmd(line, i))
		(*is_start) = true;
	else if (is_end_cmd(line, i))
		(*is_end) = true;
}
