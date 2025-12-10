#include "lem_in.h"

void	free_room_names(char *room1_name, char *room2_name)
{
	free(room1_name);
	free(room2_name);
}