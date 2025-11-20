#include "lem_in.h"

static	void	init_data(t_data *data)
{
	data->map = NULL;
	data->ant = NULL;
}

static	void	init_errors(t_data *data)
{
	data->err.gen_errors = 0;
	data->err.parsing_errors = 0;
}

void	init(t_data *data, char **argv)
{
	(void)argv;
	init_errors(data);
	init_data(data);
}
