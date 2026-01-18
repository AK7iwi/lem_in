#include "lem_in.h"

inline	bool	handle_quit(SDL_Event *event)
{
	return (event->type == SDL_EVENT_QUIT);
}
