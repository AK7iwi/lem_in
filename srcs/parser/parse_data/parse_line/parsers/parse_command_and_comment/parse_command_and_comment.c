#include "lem_in.h"

static	bool	handle_valid_cmd(t_data	*data, int fd, bool is_start, bool	is_end)
{
	char	*next_line;

	next_line = get_next_line(fd);
	if (!next_line || parse_room(data, next_line, is_start, is_end))
	{
		if (next_line)
			free(next_line);
		return (EXIT_FAILURE);
	}
	free(next_line);

	return (EXIT_SUCCESS);
}

bool	parse_command_and_comment(t_data	*data, int	fd, char	*line)
{
	size_t	i = 0;
	bool	is_start, is_end;

	skip_space(line, &i);
	if (line[i] == '#') 
	{
		if (line[i + 1] == '#')
		{
			i += 2;
			skip_space(line, &i);
			is_valid_cmd(line, i, &is_start, &is_end);
			if (is_start || is_end)
			{
				if (has_start_or_end_room(data, is_start, is_end))
					return (EXIT_FAILURE);
			}
			else
				return (EXIT_SUCCESS); /* Unknow command */
		}
		else
			return (EXIT_SUCCESS); /* Comment */
	}
	else
		return (EXIT_FAILURE); /* Others lines */

	if (handle_valid_cmd(data, fd, is_start, is_end)) //one return if no need message error
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
