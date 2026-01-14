#include "lem_in.h"

uint32_t	calculate_map_size(t_normalize *norm, uint32_t *map_width, uint32_t *map_height) 
{
	*map_width = norm->max_x - norm->min_x;
	*map_height = norm->max_y - norm->min_y;
	if (*map_width == 0)
		*map_width = 1;
	if (*map_height == 0)
		*map_height = 1;

	return (*map_width * *map_height);
}

void	get_map_bounds(t_normalize *norm, uint32_t x, uint32_t y)
{
	if (x < norm->min_x)
		norm->min_x = x;
	if (x > norm->max_x)
		norm->max_x = x;
	if (y < norm->min_y)
		norm->min_y = y;
	if (y > norm->max_y)
		norm->max_y = y;
}
