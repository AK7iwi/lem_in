#include "lem_in.h"

static	bool	parse_line(t_data *data, int	fd, char	*line, size_t i)
{
	(void)fd;
	if (line[0] == '\0' || line[0] == '\n')
		return(data->err.parsing_errors |= E_EMPTY_LINE, EXIT_FAILURE);
	else if (i == 0 && parse_nb_ants_line(data, line))
		return (EXIT_FAILURE);
	else if (parse_room(line))
		return (EXIT_FAILURE);
	else if (parse_link(line))
		return (EXIT_FAILURE);
	else
		printf("pppp\n");

	// else 
	// {
	// 	//parse_rooms_fct
	// 	if (line == "##start")
	// 		//free(line);
	// 		//get_next_line(fd)
	// 		//store line
	// 	else if (line == "##end")
	// 		//free line
	// 		//get_next_line(fd)
	// 		//store line
	// 	else if (line[0] == "#" && line[1] == "#")
	// 		//free line
	// 		//get_next_line(fd)
	// 	else
	// 		//store_room info
	// }
	//parse_links
	return (EXIT_SUCCESS);
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
	printf("\nNumber of line:%zu\n", i);
	return (EXIT_SUCCESS);
}
