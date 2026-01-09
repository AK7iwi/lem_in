#include "lem_in.h"

static	inline	bool	handle_esc(SDL_Event *event)
{
	return (event->key.key == SDLK_ESCAPE);
}

static	void	handle_r(t_data *data, SDL_Event *event)
{
	if (event->key.key == SDLK_R)
	{
		data->norm.zoom = 1.0f;
		data->norm.pan_x = 0.0f;
		data->norm.pan_y = 0.0f;
	}
}

bool	handle_key(t_data *data, SDL_Event *event)
{
	if (event->type == SDL_EVENT_KEY_DOWN)
	{
		handle_r(data, event);
		if (handle_esc(event))
			return (1);
	}

	return (0);
}
