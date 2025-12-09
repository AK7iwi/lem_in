#ifndef ERRORS_H
# define ERRORS_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include <stdint.h>
# include <stdlib.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

/* Colors */
# define COLOR_RESET   		"\x1b[0m"
# define COLOR_RED     		"\x1b[31m"

/* Parsing errors */
# define E_ARGC				0x1

# define E_EMPTY_LINE		0x2
# define E_NUMBER			0x4

# define ERR_ARGC			"argc\n"

# define ERR_EMPTY_LINE		"empty line\n"
# define ERR_NUMBER			"First line must contain only one number\n"

/* General errors */
# define E_MEMORY			0x1

# define ERR_MEMORY			"Memory error\n"

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_err
{
	size_t		line_error;
	uint8_t		gen_errors;
	uint32_t	parsing_errors;
}	t_err;

//**********************************************//
//												//
//					  ERRORS		  			//
//												//
//**********************************************//

/* errors/display_errors.c */
void	errors_displayer(t_err error);

#endif /* ERRORS_H */