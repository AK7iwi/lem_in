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
	printf("map_width:%u\n", map_width);
	printf("map_height:%u\n", map_height);

	//calculate scales
	scale_x = (WINDOW_WIDTH - 2 * PADDING) / (float)map_width;
	scale_y = (WINDOW_HEIGHT - 2 * PADDING) / (float)map_height;
	norm->scale = (scale_x < scale_y) ? scale_x : scale_y;
	printf("norm->scale:%f\n", norm->scale);

	//calculate scale values
	map_area = map_width * map_height;
	space = ft_sqrt(map_area / nb_rooms) * norm->scale;
	printf("space:%f\n", space);
	norm->radius = space * 0.2f;
	printf("norm->radius1:%u\n", norm->radius);

	if (norm->radius > 25)
		norm->radius = 25;
	else if (norm->radius < 1)
		norm->radius = 1;
	printf("norm->radius2:%u\n", norm->radius);

	//calulcate offset
	norm->offset_x = PADDING + norm->radius - norm->min_x * norm->scale;
	norm->offset_y = PADDING + norm->radius - norm->min_y * norm->scale;
}
