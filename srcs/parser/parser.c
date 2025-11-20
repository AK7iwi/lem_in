#include "lem_in.h"

static	bool	parse_map(t_data *data, int fd)
{
	char	*line;

	(void)data;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static	inline	bool	has_more_than_one_arg(t_err *err, int argc)
{
	return ((argc != 1) && (err->parsing_errors |= E_ARGC));
}

bool	parser(t_data *data, int fd, int argc)
{
	return (has_more_than_one_arg(&data->err, argc) || parse_map(data, fd));
}
