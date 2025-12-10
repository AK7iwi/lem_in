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

/* General errors */
# define E_MEMORY			0x1
# define ERR_MEMORY			"Memory error\n"

# define E_TEST				0x2
# define ERR_TEST			"Test error\n"

/* Parsing errors */
# define E_ARGC				0x1
# define ERR_ARGC			"This program does not accept arguments\n"

# define E_EMPTY_FILE		0x2
# define ERR_EMPTY_FILE		"File is empty\n"

# define E_EMPTY_LINE		0x4
# define ERR_EMPTY_LINE		"This program does not accept empty line(s)\n"


# define E_NUMBER			0x8
# define ERR_NUMBER			"First line must contain only one number\n"

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

/* display/display_errors.c */
void	display_errors(t_err error);

#endif /* ERRORS_H */