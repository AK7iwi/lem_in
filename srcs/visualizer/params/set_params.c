#include "lem_in.h"

static	void	set_offset(t_normalize *norm)
{
	norm->offset_x = PADDING + norm->radius - norm->min_x * norm->scale;
	norm->offset_y = PADDING + norm->radius - norm->min_y * norm->scale;
}

static	void	set_radius(t_normalize *norm, uint32_t map_area, uint16_t nb_rooms)
{
	float	space;

	space = ft_sqrt(map_area / nb_rooms);
	norm->radius = space * 0.2f * norm->scale;
	if (norm->radius > 25.0f)
		norm->radius = 25.0f;
	else if (norm->radius < 1.0f)
		norm->radius = 1.0f;
}

static	void	set_scale(t_normalize *norm, uint32_t map_width, uint32_t map_height)
{
	float	scale_x, scale_y;

	scale_x = (norm->window_width - 2 * PADDING) / (float)map_width;
	scale_y = (norm->window_height - 2 * PADDING) / (float)map_height;
	norm->scale = (scale_x < scale_y) ? scale_x : scale_y;
}

void	set_render_params(t_normalize *norm, uint16_t nb_rooms)
{
	uint32_t	map_area, map_width, map_height;

	map_area = calculate_map_size(norm, &map_width, &map_height);
	set_scale(norm, map_width, map_height);
	set_radius(norm, map_area, nb_rooms);
	set_offset(norm);
}
