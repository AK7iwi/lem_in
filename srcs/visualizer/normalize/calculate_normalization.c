#include "lem_in.h"

static float	ft_sqrt(float n)
{
	float	x;
	float	prev;
	float	epsilon;

	x = n;
	epsilon = 0.00001f;
	while (true)
	{
		prev = x;
		x = (x + n / x) / 2;
		if (x - prev < epsilon && prev - x < epsilon)
			break ;
	}

	return (x);
}

// rename 
void	calculate_normalization(t_normalize *norm, uint16_t nb_rooms)
{
	uint32_t	map_width;
	uint32_t	map_height;
	float		scale_x;
	float		scale_y;
	uint32_t 	map_area;
	// float		density;
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

	len_x = map_width / ft_sqrt(nb_roooms);
	len_y = map_height / ft_sqrt(nb_rooms);

	space = ft_sqrt(len_x **2 + len_y ** 2);
	space = space * norm->scale;

	//calculate scale values
	map_area = map_width * map_height;
	// density = nb_rooms / map_area;
	space = ft_sqrt(map_area / nb_rooms);
	norm->radius = space * norm->scale * 0.2f;

	printf("norm->radius1:%u\n", norm->radius);

	if (norm->radius > 30)
		norm->radius = 30;
	else if (norm->radius < 2)
		norm->radius = 2;
	// printf("map_area:%u\n", map_area);
	// printf("density:%f\n", density);
	printf("space:%f\n", space);
	printf("norm->radius1:%u\n", norm->radius);

	norm->offset_x = PADDING + norm->radius - norm->min_x * norm->scale;
	norm->offset_y = PADDING + norm->radius - norm->min_y * norm->scale;
}
