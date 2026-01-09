#include "lem_in.h"

bool	render_event(t_data *data)
{
	SDL_Event		event;

	while (SDL_PollEvent(&event))
	{
		if (handle_quit(&event) || handle_key(data, &event))
			return (1);
		handle_zoom(data, &event);
		handle_drag(data, &event);
	}

	return (0);
}
