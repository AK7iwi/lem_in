#include "lem_in.h"

static	void	update_pan_for_zoom(t_normalize *norm, float mouse_x, float mouse_y,
									float old_zoom, float new_zoom)
{
	float	map_x, map_y;

	map_x = (mouse_x - norm->pan_x) / old_zoom;
	map_y = (mouse_y - norm->pan_y) / old_zoom;
	norm->pan_x = mouse_x - map_x * new_zoom;
	norm->pan_y = mouse_y - map_y * new_zoom;
}

static	void	update_zoom(t_normalize *norm, SDL_Event *event, float *old_zoom, float *new_zoom)
{
	*old_zoom = norm->zoom;
	if (event->wheel.y > 0)
	{
		*new_zoom = *old_zoom * 1.1f;
		if (*new_zoom > 5.0f)
			*new_zoom = 5.0f;
	}
	else
	{
		*new_zoom = *old_zoom / 1.1f;
		if (*new_zoom < 0.2f)
			*new_zoom = 0.2f;
	}
	norm->zoom = *new_zoom;
}

void	handle_zoom(t_normalize *norm, SDL_Event *event)
{
	float	mouse_x, mouse_y;
	float	old_zoom, new_zoom;

	if (event->type == SDL_EVENT_MOUSE_WHEEL)
	{
		SDL_GetMouseState(&mouse_x, &mouse_y);
		update_zoom(norm, event, &old_zoom, &new_zoom);
		update_pan_for_zoom(norm, mouse_x, mouse_y, old_zoom, new_zoom);
	}
}
