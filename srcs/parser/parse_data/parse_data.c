#include "lem_in.h"

static	bool	parse_line(t_data *data, int	fd, char	*line, size_t	i)
{	
	if (!line || is_last_char(line[0]))
		return(data->err.parsing_errors |= E_EMPTY_LINE, EXIT_FAILURE);
	if (i == 0 && !parse_nb_ants_line(data, line))
		return (EXIT_SUCCESS);
	if (!parse_command_and_comment(data, fd, line)
		|| !parse_room(data, line, false, false)
		|| !parse_link(data, line))
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}

bool	parse_data(t_data *data, int fd)
{
	char	*line;
	size_t  i;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE); //empty file message error
	i = 0;
	while (line)
	{
		if (parse_line(data, fd, line, i))
			return (free(line), EXIT_FAILURE);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (!data->map->has_start)
		return (EXIT_FAILURE); // start error
	if (!data->map->has_end)
		return (EXIT_FAILURE); //end error
	return (EXIT_SUCCESS);
}
