#include "lem_in.h"

static	bool	parse_line(t_data *data, int	fd, char	*line, size_t	i)
{	
	if (is_last_char(line[0]))
		return(data->err.parsing_errors |= E_EMPTY_LINE, EXIT_FAILURE);
	if (i == 0 && !parse_nb_ants_line(data, line))
		return (EXIT_SUCCESS);
	if (!parse_comment(data, fd, line) 
		|| !parse_room(data, line, false, false) 
		|| !parse_link(line))
		return (EXIT_SUCCESS);

	printf("ERROR\n");
	return (EXIT_FAILURE);
}

bool	parse_data(t_data *data, int fd)
{
	char	*line;
	size_t  i;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		printf("%s", line);
		if (parse_line(data, fd, line, i))
			return (free(line), EXIT_FAILURE);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
