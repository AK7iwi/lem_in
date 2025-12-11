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

# define E_ANTS_VALUE		0x8
# define ERR_ANTS_VALUE		"Number of ants must be between 1 and 1000000\n"

# define E_TWO_STARTS		0x10
# define ERR_TWO_STARTS		"There must be exactly one start room\n"
# define E_TWO_ENDS			0x20
# define ERR_TWO_ENDS		"There must be exactly one end room\n"
# define E_START			0x40
# define ERR_START			"Start room is missing or invalid\n"
# define E_END				0x80
# define ERR_END			"End room is missing or invalid\n"


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