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
# define COLOR_RESET   				"\x1b[0m"
# define COLOR_RED     				"\x1b[31m"

/* General errors */
# define E_MEMORY					0x1
# define ERR_MEMORY					"Memory error\n"

/* Parsing errors */
# define E_ARGC						0x1
# define ERR_ARGC					"This program does not accept arguments\n"

# define E_EMPTY_FILE				0x2
# define ERR_EMPTY_FILE				"Empty or missing file\n"

# define E_EMPTY_LINE				0x4
# define ERR_EMPTY_LINE				"This program does not accept empty line(s)\n"

# define E_ANTS_VALUE				0x8
# define ERR_ANTS_VALUE				"Number of ants must be between 1 and 1000000\n"

# define E_TWO_STARTS				0x10
# define ERR_TWO_STARTS				"There must be exactly one start room\n"
# define E_TWO_ENDS					0x20
# define ERR_TWO_ENDS				"There must be exactly one end room\n"
# define E_START					0x40
# define ERR_START					"Start room is missing or invalid\n"
# define E_END						0x80
# define ERR_END					"End room is missing or invalid\n"

# define E_ANTS_AND_ROOMS_MIXED		0X100
# define ERR_ANTS_AND_ROOMS_MIXED	"Number of ants must be the first line and a positive number betwenn 1 and 1000000\n"
# define E_ROOM_EXISTS				0x200
# define ERR_ROOM_EXISTS			"The room already exists\n"
# define E_COORDS_VALUES			0x400
# define ERR_COORDS_VALUES			"Coordinates must be between 0 and 1000000\n"
# define E_COORDS_EXIST				0X800
# define ERR_COORDS_EXIST			"There is already a room at these coordinates\n"
# define E_NB_ROOMS					0x1000
# define ERR_NB_ROOMS				"Number of rooms must be between 2 and 10000\n"

# define E_ROOMS_AND_LINKS_MIXED	0x2000
# define ERR_ROOMS_AND_LINKS_MIXED	"Rooms must be defined before links\n"
# define E_ROOM_NOT_FOUND			0x4000
# define ERR_ROOM_NOT_FOUND			"Room does not exist\n"
# define E_SAME_ROOM				0x8000
# define ERR_SAME_ROOM				"A link cannot connect a room to itself\n"
# define E_LINK_EXISTS				0x10000
# define ERR_LINK_EXISTS			"Link already exists\n"
# define E_NB_LINKS					0x20000
# define ERR_NB_LINKS				"Not enough links to connect all rooms\n"
# define E_NO_PATH					0x40000
# define ERR_NO_PATH				"No path exists between start and end rooms\n"

# define ERR_FORMAT					"Invalid line format\n\n" \
									"Expected format:\n" \
									" - Ants: positive integer (1-2000)\n" \
									" - Room: name x y (coordinates 0-1000000)\n" \
									" - Link: room1-room2\n" \
									" - Command: ##start or ##end (one each required)\n" \
									" - Comment: #text\n\n" \
									"Example:\n" \
									"3\n" \
									"##start\n" \
									"0 1 0\n" \
									"##end\n" \
									"1 5 0\n" \
									"2 9 0\n" \
									"3 13 0\n" \
									"0-2\n" \
									"2-3\n" \
									"3-1\n"

/* Visualizer errors */
# define E_VISU						0x1
# define ERR_VISU					"Couldn't create window/renderer\n"

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_err
{
	size_t		line_error;
	uint8_t		gen_errors;
	uint32_t	parsing_errors;
	uint8_t		visu_errors;
}	t_err;

//**********************************************//
//												//
//					  ERRORS		  			//
//												//
//**********************************************//

/* display/display_errors.c */
void	display_errors(t_err error);

#endif /* ERRORS_H */