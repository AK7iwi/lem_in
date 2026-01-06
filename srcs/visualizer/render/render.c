#include "lem_in.h"

void	close_render(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static  bool	render_event(t_data *data)
{
	SDL_Event		event;
	float			mouse_x, mouse_y;
	float			old_zoom, new_zoom;
	float			world_x, world_y;
	static bool		is_dragging = false;
	static float	drag_start_x = 0.0f;
	static float	drag_start_y = 0.0f;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
			return (1);
		else if (event.type == SDL_EVENT_MOUSE_WHEEL)
		{
			SDL_GetMouseState(&mouse_x, &mouse_y);
			old_zoom = data->norm.zoom;
			
			if (event.wheel.y > 0)
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
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
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
			mouse_x = event.motion.x;
			mouse_y = event.motion.y;
			data->norm.pan_x += (mouse_x - drag_start_x);
			data->norm.pan_y += (mouse_y - drag_start_y);
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
		}
	}

	return (0);
}

void	render(SDL_Renderer *renderer, t_data *data)
{
	bool	running = true;

	while (running)
	{
		if (render_event(data))
			running = false;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderScale(renderer, data->norm.zoom, data->norm.zoom);
		draw_render(renderer, data);
		SDL_RenderPresent(renderer);
	}
}

bool    init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer)
{
	const SDL_DisplayMode	*display_mode;

	if (!SDL_Init(SDL_INIT_VIDEO))
		return (data->err.visu_errors |= E_VISU, 1);

	/* Use 90% of screen size */
	display_mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
	if (display_mode)
	{
		data->norm.window_width = (uint16_t)(display_mode->w * 0.9f);
		data->norm.window_height = (uint16_t)(display_mode->h * 0.9f);
	}
	if (!SDL_CreateWindowAndRenderer("Lem-in Visualizer", data->norm.window_width, data->norm.window_height,
			SDL_WINDOW_RESIZABLE, window, renderer))
	{
		SDL_Quit();
		return (data->err.visu_errors |= E_VISU, 1);
	}
	SDL_SetRenderLogicalPresentation(*renderer, data->norm.window_width, data->norm.window_height,
		SDL_LOGICAL_PRESENTATION_LETTERBOX);

	return (0);
}
