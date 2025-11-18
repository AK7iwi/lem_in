#ifndef ERRORS_H
# define ERRORS_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

#include <stdint.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

/* Colors */
# define COLOR_RESET   "\x1b[0m"
# define COLOR_RED     "\x1b[31m"

/* Parsing errors */
# define ERR_1			0x1


# define E_QUOTE		"E1\n"


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

/* */



#endif /* ERRORS_H */