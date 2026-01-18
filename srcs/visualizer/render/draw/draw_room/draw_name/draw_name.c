#include "lem_in.h"

bool	draw_name(SDL_Renderer *renderer, char *name, float x, float y)
{
	uint8_t		text_width;
	float		offset_x;

	text_width = ft_strlen(name) * 8;
	offset_x = text_width / 2;

	return (!SDL_RenderDebugText(renderer, x - offset_x, y - 4, name));
}
