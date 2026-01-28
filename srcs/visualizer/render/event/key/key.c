#include "lem_in.h"

static	inline	bool	handle_esc(SDL_Event *event)
{
	return (event->key.key == SDLK_ESCAPE);
}

static	void	handle_r(t_normalize *norm, SDL_Event *event)
{
	if (event->key.key == SDLK_R)
	{
		norm->zoom = 1.0f;
		norm->pan_x = 0.0f;
		norm->pan_y = 0.0f;
	}
}

bool	handle_key(t_normalize *norm, SDL_Event *event)
{
	if (event->type == SDL_EVENT_KEY_DOWN)
	{
		handle_r(norm, event);
		if (handle_esc(event))
			return (1);
	}

	return (0);
}
