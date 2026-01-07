#include "lem_in.h"

static	void	handle_zoom_event(t_data *data, SDL_Event *event)
{
	float	mouse_x, mouse_y;
	float	old_zoom, new_zoom;
	float	world_x, world_y; //rename

	/* */
	SDL_GetMouseState(&mouse_x, &mouse_y);
	// print
	old_zoom = data->norm.zoom;

	if (event->wheel.y > 0)
	{
		new_zoom = old_zoom * 1.1f;
		if (new_zoom > 5.0f)
			new_zoom = 5.0f;
	}
	else
	{
		new_zoom = old_zoom / 1.1f;
		if (new_zoom < 0.2f)
			new_zoom = 0.2f;
	}

	world_x = (mouse_x - data->norm.pan_x) / old_zoom;
	world_y = (mouse_y - data->norm.pan_y) / old_zoom;
	data->norm.zoom = new_zoom;
	data->norm.pan_x = mouse_x - world_x * new_zoom;
	data->norm.pan_y = mouse_y - world_y * new_zoom;
}

bool	render_event(t_data *data)
{
	SDL_Event		event;
	float			mouse_x, mouse_y;
	static bool		is_dragging = false;
	static float	drag_start_x = 0.0f;
	static float	drag_start_y = 0.0f;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT) //handle_quit
			return (1);
		else if (event.type == SDL_EVENT_MOUSE_WHEEL) //handle_zoom_event
			handle_zoom_event(data, &event);
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) //handle_drag
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				is_dragging = true;
				drag_start_x = event.button.x;
				drag_start_y = event.button.y;
			}
		}
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				is_dragging = false;
		}
		else if (event.type == SDL_EVENT_MOUSE_MOTION && is_dragging)
		{
			/* */
			mouse_x = event.motion.x;
			mouse_y = event.motion.y;
			// print
			data->norm.pan_x += mouse_x - drag_start_x;
			data->norm.pan_y += mouse_y - drag_start_y;
			drag_start_x = mouse_x;
			drag_start_y = mouse_y;
		}
		else if (event.type == SDL_EVENT_KEY_DOWN)
		{
			if (event.key.key == SDLK_R)
			{
				data->norm.zoom = 1.0f;
				data->norm.pan_x = 0.0f;
				data->norm.pan_y = 0.0f;
			} 
			// if (event.key.key == SDLK_ESC)

		}
	}

	return (0);
}
