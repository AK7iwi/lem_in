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

typedef struct s_room_link
{
	t_room				*room;
	uint8_t				pheromones_rate;

	struct s_room_link	*next;
}	t_room_link;

typedef struct s_room
{
	char		*name;
	uint16_t	x;
	uint16_t	y;
	bool		is_empty;
	bool		is_start;
	bool		is_end;

	t_room_link	*link;
}	t_room;

typedef struct s_map
{
	uint16_t	nb_rooms;
	t_room		*rooms;
}	t_map;

typedef struct s_ant
{
	uint16_t		id;
	t_room			*current_room;
	bool			has_moved;

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
//					  TOOLS		  				//
//												//
//**********************************************//

/* tools/convert_type/ft_atoi.c */
int		ft_atoi(const char *nptr);

/* tools/check_type/check_type.c */
bool	is_last_char(char c);
bool	is_alnum(int c);
bool	is_digit(int c);

/* tools/print/print.c */
void	ft_putchar(char c, int fd);
void	ft_putnbr(int	n, int	fd);
void	ft_putstr(char *str, int	fd);

/* tools/free/free_data.c */
void	free_data(t_data *data);

//**********************************************//
//												//
//					  DISPLAYER		  			//
//												//
//**********************************************//

/* displayer/tools/find_room.c */
t_room	*find_end_room(t_map *map);
t_room	*find_start_room(t_map *map);

/* displayer/print_general_infos.c */
void    print_general_infos(t_data  *data);

//**********************************************//
//												//
//					  PARSER		  			//
//												//
//**********************************************//

/* parser/parse_data/tools/parse_data_tools.c */
t_room	*is_existing_room(t_data *data, char *line, size_t *i);
bool	is_end_room(char	*line, size_t	i);
bool	is_start_room(char	*line, size_t	i);
bool	is_valid_name(t_data	*data, char	*line, size_t	*i);
bool	is_valid_number(char	*line, size_t	*i);
void	skip_space(char	*line, size_t	*i);

/* parser/parse_data/parse_line_type.c */
bool	parse_link(t_data *data, char	*line);
bool	parse_room(t_data *data, char	*line, bool	is_start, bool	is_end);
bool	parse_comment(t_data *data, int	fd, char	*line);
bool	parse_nb_ants_line(t_data *data, char	*line);

/* parser/parse_data/parse_data.c */
bool	parse_data(t_data *data, int fd);

/* parser/parser.c */
bool	parser(t_data *data, int fd, int argc);

//**********************************************//
//												//
//					INITIALIZER  				//
//												//
//**********************************************// 

/* init/init_struct/init_link.c */
bool	init_link(t_room *room1, t_room *room2);
/* init/init_struct/init_room.c */
bool	init_room(t_data *data, char *line, size_t name_start, size_t name_end, size_t x_start, size_t x_end, size_t y_start, size_t y_end, bool is_start, bool is_end);
/* init/init_struct/init_nb_ants.c */
void	init_nb_ants(t_data *data, char *line);

/* init/init.c */
bool	init(t_data *data, char **argv);

#endif /* LEM_IN_H */
