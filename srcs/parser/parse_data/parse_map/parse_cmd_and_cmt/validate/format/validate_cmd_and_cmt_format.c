#include "lem_in.h"

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
		|| line[i + 3] != 'r' || line[i + 4] != 't')
		return (false);
	i += 5;
	skip_space(line, &i);

	return (is_last_char(line[i]));
}

static	void	is_valid_cmd(char *line, size_t	i, bool	*is_start, bool	*is_end)
{
	if (is_start_cmd(line, i))
		*is_start = true;
	else if (is_end_cmd(line, i))
		*is_end = true;
}

static	inline	bool	is_cmt(char *line, size_t i)
{
	return (line[i + 1] != '#');
}

static	inline	bool	is_cmd_or_cmt(char *line, size_t i)
{
	return (line[i] == '#');
}

bool	validate_cmd_and_cmt_format(char *line, bool *is_start, bool *is_end)
{
	size_t	i = 0;

	skip_space(line, &i);
	if (!is_cmd_or_cmt(line, i))
		return (1);
	if (is_cmt(line, i))
		return (0);
	i += 2;
	skip_space(line, &i);
	is_valid_cmd(line, i, is_start, is_end);

	return (0);
}
