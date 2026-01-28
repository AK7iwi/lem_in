#include "lem_in.h"

bool	event_handler(t_normalize *norm)
{
	SDL_Event		event;

	while (SDL_PollEvent(&event))
	{
		if (handle_quit(&event) || handle_key(norm, &event))
			return (1);
		handle_zoom(norm, &event);
		handle_drag(norm, &event);
	}

	return (0);
}
