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
//					DEFINES						//
//**********************************************//

// modify later in function of performance

# define MAX_ANTS	1000000
# define MIN_ANTS	1
# define MAX_ROOMS	10000
# define MIN_ROOMS	2
#define  MAX_COORDINATE (MAX_ROOMS * 100)

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_room	t_room;

typedef struct s_link
{
	t_room			*room;
	uint8_t			pheromones_rate;

	struct s_link	*next;
}	t_link;

typedef struct s_room
{
	char		*name;
	uint32_t	x;
	uint32_t	y;
	bool		is_empty;

	t_link		*link;
}	t_room;

typedef struct s_map
{
	uint16_t	nb_rooms;
	uint16_t	capacity;
	uint16_t	nb_links;
	uint16_t	nb_valid_cmds;
	t_room		*rooms;
	t_room		*start_room;
	t_room		*end_room;
}	t_map;

typedef struct s_ant
{
	uint32_t		id;
	t_room			*current_room;
	bool			has_moved;

	struct s_ant	*next;
}	t_ant;

typedef struct s_data
{
	// uint16_t	moves;
	// uint16_t	time;
	uint32_t	nb_ants;

	t_err		err;
	t_ant		*ant;
	t_map		*map;
}	t_data;

//**********************************************//
//												//
//					  FREE		  				//
//												//
//**********************************************//

/* free_data.c */
void	free_data(t_data *data);

//**********************************************//
//												//
//					  DISPLAYER		  			//
//												//
//**********************************************//

/* tools/print.c */
void	ft_putnbr(int	n, int	fd);
void	ft_putstr(char *str, int	fd);
void	ft_putchar(char	c, int	fd);

/* display_map.c */
bool	print_map(t_data *data);
/* display_infos.c */
void	display_infos(t_data *data);
/* display_errors.c */
void	display_errors(t_err error);

//**********************************************//
//												//
//					  PARSER		  			//
//												//
//**********************************************//

/* parse_data/bfs_algo/tools/room_index.c */
size_t	get_room_index(t_map *map, t_room *room);
/* parse_data/bfs_algo/tools/free_array.c */
void	free_bfs_arrays(bool *visited, t_room **queue);
/* parse_data/bfs_algo/bfs.c */
bool	has_path(t_map	*map);


/* parse_data/parse_line/parsers/common/tools/check_char_type.c */
bool	is_alnum(int c);
bool	is_digit(int c);

/* parse_data/parse_line/parsers/common/extract/extract_data.c */
char	*extract_name(t_data *data, char *line, size_t name_start, size_t name_end);

/* parse_data/parse_line/parsers/common/validate/validate_data.c */
t_room	*is_existing_room(t_data *data, char *name);
bool	validate_name(char *line, size_t *i, size_t *name_start, size_t *name_end);
bool	is_valid_number(char *line, size_t *i);


/* parse_data/parse_line/parsers/parse_link/tools/free_rooms.c */
void	free_room_names(char *room1_name, char *room2_name);
/* parse_data/parse_line/parsers/parse_link/create/create_link.c */
bool	create_link(t_data *data, t_room *room1, t_room *room2);
/* parse_data/parse_line/parsers/parse_link/extract/extract_link.c */
bool	extract_room_names(t_data *data, char *line, char **room1_name, size_t room1_start, size_t room1_end, char **room2_name, size_t room2_start, size_t room2_end);
/* parse_data/parse_line/parsers/parse_link/validate/validate_link_values.c */
bool	validate_link_values(t_data *data, t_room **room1, char *room1_name, t_room **room2, char *room2_name);
/* parse_data/parse_line/parsers/parse_link/validate/validate_link_format.c */
bool	validate_link_format(t_data *data, char *line, size_t *room1_start, size_t *room1_end, size_t *room2_start, size_t *room2_end);
/* parse_data/parse_line/parsers/parse_link/validate/validate_link.c */
bool	validate_link(t_data *data, char *line, t_room **room1, t_room **room2);
/* parse_data/parse_line/parsers/parse_link/parse_link.c */
bool	parse_link(t_data *data, char *line);


/* parse_data/parse_line/parsers/parse_room/create/create_room.c */
bool	create_room(t_data	*data, char	*name, uint32_t	x, uint32_t	y, bool	is_start, bool	is_end);
/* parse_data/parse_line/parsers/parse_room/extract/extract_room.c */
bool	extract_room_data(t_data *data, char *line, char **name, uint32_t *x, uint32_t *y, size_t name_start, size_t name_end, size_t x_start, size_t x_end, size_t y_start, size_t y_end);
/* parse_data/parse_line/parsers/parse_room/validate/validate_room_values.c */
bool    validate_room_values(t_data *data, char *name, uint32_t x, uint32_t y);
/* parse_data/parse_line/parsers/parse_room/validate/validate_room_format.c */
bool	validate_room_format(t_data *data, char *line, size_t *name_start, size_t *name_end, size_t *x_start, size_t *x_end, size_t *y_start, size_t *y_end);
/* parse_data/parse_line/parsers/parse_room/validate/validate_room.c */
bool	validate_nb_rooms(t_data *data);
bool	validate_room(t_data *data, char *line, char **name, uint32_t *x, uint32_t *y);
/* parse_data/parse_line/parsers/parse_room/parse_room.c */
bool	parse_room(t_data *data, char *line, bool is_start, bool is_end);


/* parse_data/parse_line/parsers/parse_cmd_and_cmt/create/create_cmd.c */
bool	create_cmd(t_data *data, int fd, bool is_start, bool is_end);
/* parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt_value.c */
bool	validate_cmd_and_cmt_value(t_data *data, bool is_start, bool is_end);
/* parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt_format.c */
bool	validate_cmd_and_cmt_format(char *line, bool *is_start, bool *is_end);
/* parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt.c */
bool	validate_cmd_and_cmt(t_data	*data, char	*line, bool *is_start, bool *is_end);
/* parse_data/parse_line/parsers/parse_cmd_and_cmt/parse_cmd_and_cmt.c */
bool	parse_cmd_and_cmt(t_data *data, int fd, char *line);


/* parse_data/parse_line/parsers/parse_ants/tools/ft_atoi.c */
int		ft_atoi(const char *nptr);
/* parse_data/parse_line/parsers/parse_ants/create/set_start_room.c */
void	set_start_room(t_data *data);
/* parse_data/parse_line/parsers/parse_ants/create/create_ants.c */
bool	create_ants(t_data *data, uint32_t nb_ants);
/* parse_data/parse_line/parsers/parse_ants/extract_ants.c */
void	extract_nb_ants(char *line, uint32_t *nb_ants);
/* parse_data/parse_line/parsers/parse_ants/validate/validate_ants_value.c */
bool	validate_ants_value(uint32_t nb_ants);
/* parse_data/parse_line/parsers/parse_ants/validate/validate_ants_format.c */
bool	validate_ants_format(char *line);
/* parse_data/parse_line/parsers/parse_ants/validate/validate_ants.c */
bool	validate_ants(t_data *data, char *line, uint32_t *nb_ants);
/* parse_data/parse_line/parsers/parse_ants/parse_ants.c */
bool	parse_ants(t_data *data, char *line);


/* parse_data/parse_line/tools/last_char.c */
bool	is_last_char(char c);
/* parse_data/parse_line/tools/skip_space_char.c */
void	skip_space(char	*line, size_t *i);
/* parse_data/parse_line/tools/empty_line.c */
bool	is_empty_line(char *line);


/* parse_data/parse_line/parse_line.c */
bool	parse_line(t_data *data, int fd, char *line);


/* parse_data/parse_data.c */
bool	parse_data(t_data *data, int fd);


/* parse_arg/validate_arg.c */
bool	has_no_arg(int	argc);


/* parser.c */
bool	parser(t_data *data, int fd, int argc);

//**********************************************//
//												//
//					  INIT		  				//
//												//
//**********************************************// 

/* init.c */
bool	init(t_data *data, char **argv);

#endif /* LEM_IN_H */
