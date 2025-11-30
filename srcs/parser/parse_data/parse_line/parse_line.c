#include "lem_in.h"

bool	parse_line(t_data	*data, int	fd, char	*line, size_t	i)
{	
	if (i == 0 && !parse_ants_line(data, line))
		return (EXIT_SUCCESS);
	if (!parse_command_and_comment(data, fd, line)
		|| !parse_room(data, line, false, false)
		|| !parse_link(data, line))
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}

uint8_t	parse_empty_line(t_data	*data, int	fd, char	*line)
{
	char	*next_line;

	if (is_last_char(line[0])) //test if spaces on the line
	{
		next_line = get_next_line(fd);
		while (next_line && is_last_char(next_line[0]))
		{
			free(next_line);
			next_line = get_next_line(fd);
		}
		if (!next_line)
			return (1);
		free(next_line);
		return (data->err.parsing_errors |= E_EMPTY_LINE, 2); //Not needed because an error will be return after in parse_line but good for the error message. Check if keep 
	}
	return (0);
}
