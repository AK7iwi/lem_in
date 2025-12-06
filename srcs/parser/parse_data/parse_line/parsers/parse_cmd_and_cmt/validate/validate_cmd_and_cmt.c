#include "lem_in.h"

static	bool	has_start_or_end_room(t_data *data, bool is_start, bool is_end)
{
	if (is_start && data->map->start_room)
		return (1); //two start error
	else if (is_end && data->map->end_room)
		return (1); //two end error

	return (0);
}

static	bool	is_end_cmd(char *line, size_t i)
{
	if (line[i] != 'e' || line[i + 1] != 'n' || line[i + 2] != 'd')
		return (false);
	i+= 3;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

static	bool	is_start_cmd(char *line, size_t i)
{
	if (line[i] != 's' || line[i + 1] != 't' || line[i + 2] != 'a'
		||line[i + 3] != 'r' || line[i + 4] != 't')
		return (false);
	i += 5;
	skip_space(line, &i);
	return (is_last_char(line[i]));
}

static	void	is_valid_cmd(char *line, size_t	i, bool	*is_start, bool	*is_end)
{
	if (is_start_cmd(line, i))
		(*is_start) = true;
	else if (is_end_cmd(line, i))
		(*is_end) = true;
}

static	bool	validate_cmd_and_cmt_format(char *line, bool *is_start, bool *is_end)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (line[i] != '#')
		return (1);  /* Others lines */
	if (line[i + 1] != '#')
		return (0); /* Comment */
	i += 2;
	skip_space(line, &i);
	is_valid_cmd(line, i, is_start, is_end);

	return (0);
}

bool	validate_cmd_and_cmt(t_data	*data, char	*line, bool *is_start, bool *is_end)
{
	(*is_start) = false;
	(*is_end) = false;

	if (validate_cmd_and_cmt_format(line, is_start, is_end))
		return (1);
	if (has_start_or_end_room(data, *is_start, *is_end))
		return (1);

	return (0);
}
