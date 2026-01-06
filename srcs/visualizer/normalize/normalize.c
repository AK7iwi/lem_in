#include "lem_in.h"

void	normalize_coordinates(t_normalize *norm, uint32_t x, float *screen_x, uint32_t y, float *screen_y)
{
	*screen_x = x * norm->scale + norm->offset_x + norm->pan_x / norm->zoom;
	*screen_y = y * norm->scale + norm->offset_y + norm->pan_y / norm->zoom;
}

void	get_map_limits(t_normalize *norm, uint32_t x, uint32_t y)
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
