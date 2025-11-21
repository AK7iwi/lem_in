#ifndef ERRORS_H
# define ERRORS_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include <stdint.h>

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

# define ERR_ARGC			"ERROR: argc\n"

# define ERR_EMPTY_LINE		"ERROR: empty line\n"
# define ERR_NUMBER			"ERROR: First line must contain only one number\n"


//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_err
{
	uint8_t		gen_errors;
	uint16_t	parsing_errors;
}	t_err;

//**********************************************//
//												//
//					  ERRORS		  			//
//												//
//**********************************************//

/* errors/display_errors.c */
void	errors_displayer(t_err error);

#endif /* ERRORS_H */