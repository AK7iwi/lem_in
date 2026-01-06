#include "lem_in.h"

// rename 
void	calculate_normalization(t_normalize *norm, uint16_t nb_rooms)
{
	uint32_t	map_width;
	uint32_t	map_height;
	float		scale_x;
	float		scale_y;
	uint32_t 	map_area;
	float		space;

	//calculate map_size
	map_width = norm->max_x - norm->min_x;
	map_height = norm->max_y - norm->min_y;
	if (map_width == 0)
		map_width = 1;
	if (map_height == 0)
		map_height = 1;

	//calculate scales
	scale_x = (norm->window_width - 2 * PADDING) / (float)map_width;
	scale_y = (norm->window_height - 2 * PADDING) / (float)map_height;
	norm->scale = (scale_x < scale_y) ? scale_x : scale_y;

	//calculate radius
	map_area = map_width * map_height;
	space = ft_sqrt(map_area / nb_rooms);
	norm->radius = space * 0.2f * norm->scale;

	if (norm->radius > 25.0)
		norm->radius = 25.0;
	else if (norm->radius < 1.0)
		norm->radius = 1.0;

	//calulcate offset
	norm->offset_x = PADDING + norm->radius - norm->min_x * norm->scale;
	norm->offset_y = PADDING + norm->radius - norm->min_y * norm->scale;
}
