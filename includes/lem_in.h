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

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_data
{
	t_err	err;
}	t_data;

//**********************************************//
//												//
//					  TOOLS		  				//
//												//
//**********************************************// 

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
