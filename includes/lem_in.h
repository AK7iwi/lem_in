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

	t_room_link	*link;
}	t_room;

typedef struct s_map
{
	uint16_t	nb_rooms;
	t_room		*rooms;
	t_room		*start_room;
	t_room		*end_room;
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

/* parser/parse_data/parse_data.c */
bool	parse_data(t_data *data, int fd);

/* tools/print/print.c */
void	ft_putstr(char *str);

//**********************************************//
//												//
//					  PARSER		  			//
//												//
//**********************************************//

/* parser/parser.c */
bool	parser(t_data *data, int fd, int argc);

//**********************************************//
//												//
//					INITIALIZER  				//
//												//
//**********************************************// 

/* init/init.c */
void	init(t_data *data, char **argv);

#endif /* LEM_IN_H */
