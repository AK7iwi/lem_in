#ifndef LEM_IN_H
# define LEM_IN_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_room	t_room;

typedef struct s_link
{
	t_room	*room;
	uint8_t	pheromones_rate;

	struct s_link	*next;
}	t_link;

typedef struct s_room
{
	char		*name;
	uint32_t	x;
	uint32_t	y;
	bool		is_empty;

	t_link	*link;
}	t_room;

typedef struct s_map
{
	uint16_t	nb_rooms;
	uint16_t	capacity;
	uint16_t	nb_links;
	t_room		*rooms;
	t_room		*start_room;
	t_room		*end_room;
}	t_map;

typedef struct s_ant
{
	uint16_t	id;
	t_room		*current_room;
	bool		has_moved;

	struct s_ant	*next;
}	t_ant;

typedef struct s_data
{
	uint16_t	moves;
	uint16_t	time;
	uint16_t	nb_ants;

	t_err		err;
	t_ant		*ant;
	t_map		*map;
}	t_data;

//**********************************************//
//												//
//					  FREE		  				//
//												//
//**********************************************//

/* free/free_data.c */
void	free_data(t_data *data);

//**********************************************//
//												//
//					  DISPLAYER		  			//
//												//
//**********************************************//

/* displayer/tools/print.c */
void	ft_putnbr(int	n, int	fd);
void	ft_putstr(char *str, int	fd);
void	ft_putchar(char	c, int	fd);

/* displayer/display_map.c */
bool	print_map(t_data *data);

/* displayer/display_infos.c */
void	display_infos(t_data *data);

/* displayer/display_errors.c */
void	errors_displayer(t_err error);

//**********************************************//
//												//
//					  PARSER		  			//
//												//
//**********************************************//

/* parser/parse_data/bfs_algo/bfs.c */
bool    has_path(t_map	*map);

/* parser/parse_data/parse_line/tools/check_char_type.c */
bool	is_last_char(char c);
bool	is_digit(int c);
/* parser/parse_data/parse_line/tools/skip_space_char.c */
void	skip_space(char	*line, size_t	*i);

/* parser/parse_data/parse_line/validate_data/validate_data.c */
t_room	*is_existing_room(t_data	*data, char	*line, size_t	*i);
bool	is_valid_number(char	*line, size_t	*i);

/* parser/parse_data/parse_line/parse_link/validate_data/validate_link_data.c */
bool	is_existing_link(t_room	*room, t_room	*target_room);
/* parser/parse_data/parse_line/parse_link/parse_link.c */
bool	parse_link(t_data *data, char *line);

/* parser/parse_data/parse_line/parse_room/tools/check_char_type.c */
bool	is_alnum(int c);
/* parser/parse_data/parse_line/parse_room/extract_data/extract_room_data.c */
bool	extract_room_data(t_data	*data, char *line, char	**name, uint32_t *x, uint32_t	*y, size_t	name_start,	size_t	name_end, size_t	x_start, size_t	x_end, size_t	y_start, size_t y_end);
/* parser/parse_data/parse_line/parse_room/validate_data/validate_room_data.c */
bool	is_existing_coordinates(t_data *data, uint16_t x, uint16_t y);
bool	is_valid_name(t_data	*data, char	*line, size_t	*i);
/* parser/parse_data/parse_line/parse_room/parse_room.c */
bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end);

/* parser/parse_data/parse_line/parse_command_and_comment/validate_data/validate_command_and_comment_data.c */
bool	is_end_cmd(char	*line, size_t	i);
bool	is_start_cmd(char	*line, size_t	i);
/* parser/parse_data/parse_line/parse_command_and_comment/parse_command_and_comment.c */
bool	parse_command_and_comment(t_data	*data, int	fd, char	*line);

/* parser/parse_data/parse_line/parse_ants/tools/ft_atoi.c */
int		ft_atoi(const char *nptr);
/* parser/parse_data/parse_line/parse_ants/parse_ants.c */
bool	parse_ants_line(t_data *data, char	*line);

/* parser/parse_data/parse_line/parse_line.c */
bool	parse_line(t_data	*data, int	fd, char	*line, size_t	i);
uint8_t	parse_empty_line(t_data	*data, int	fd, char	*line);

/* parser/parse_data/parse_data.c */
bool	parse_data(t_data	*data, int	fd);

/* parser/parser.c */
bool	parser(t_data	*data, int	fd, int	argc);

//**********************************************//
//												//
//					  INIT		  				//
//												//
//**********************************************// 

/* init/init_struct/init_link.c */
bool	init_link(t_room *room1, t_room *room2);
/* init/init_struct/init_room.c */
bool	init_room(t_data	*data, char	*name, uint32_t	x, uint32_t	y, bool	is_start, bool	is_end);
/* init/init_struct/init_nb_ants.c */
void	init_nb_ants(t_data *data, char *line);

/* init/init.c */
bool	init(t_data *data, char **argv);

#endif /* LEM_IN_H */
