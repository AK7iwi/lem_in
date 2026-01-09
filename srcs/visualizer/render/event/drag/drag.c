#include "lem_in.h"

static	void	update_pan_while_dragging(t_data *data, SDL_Event *event,
										bool is_dragging, float *drag_start_x,
										float *drag_start_y)
{
	float	mouse_x, mouse_y;

	if (event->type == SDL_EVENT_MOUSE_MOTION && is_dragging)
	{
		mouse_x = event->motion.x;
		mouse_y = event->motion.y;
		data->norm.pan_x += mouse_x - *drag_start_x;
		data->norm.pan_y += mouse_y - *drag_start_y;
		*drag_start_x = mouse_x;
		*drag_start_y = mouse_y;
	}
}

static	void	stop_drag(SDL_Event *event, bool *is_dragging)
{
	if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && event->button.button == SDL_BUTTON_LEFT)
		*is_dragging = false;
}

static	void	start_drag(SDL_Event *event, bool *is_dragging,
						float *drag_start_x, float *drag_start_y)
{
	if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT)
	{
		*is_dragging = true;
		*drag_start_x = event->button.x;
		*drag_start_y = event->button.y;
	}
}

void	handle_drag(t_data *data, SDL_Event *event)
{
	static bool		is_dragging = false;
	static float	drag_start_x = 0.0f;
	static float	drag_start_y = 0.0f;

	start_drag(event, &is_dragging, &drag_start_x, &drag_start_y);
	stop_drag(event, &is_dragging);
	update_pan_while_dragging(data, event, is_dragging, &drag_start_x, &drag_start_y);
}
