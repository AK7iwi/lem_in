#include "lem_in.h"

bool	parse_command_and_comment(t_data	*data, int	fd, char	*line)
{
	size_t	i = 0;
	bool	is_start, is_end;
	char	*next_line;

	skip_space(line, &i);
	if (line[i] == '#') 
	{
		if (line[i + 1] == '#')
		{
			i += 2;
			skip_space(line, &i);
			//is_valid_cmd
			is_start = is_start_cmd(line, i);
			is_end = is_end_cmd(line, i);
			if (is_start)
			{
				if (data->map->start_room)
					return (EXIT_FAILURE); // two start error
			}
			else if (is_end)
			{
				if (data->map->end_room)
					return (EXIT_FAILURE); // two end error
			}
			else
				return (EXIT_SUCCESS); /* Unknow command */
		}
		else
			return (EXIT_SUCCESS); /* Comment */
	}
	else
		return (EXIT_FAILURE); /* Others lines */
	//handle next line fct
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
