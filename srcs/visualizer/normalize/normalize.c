#include "lem_in.h"

void	normalize_coordinates(t_normalize *norm, uint32_t x, float *screen_x, uint32_t y, float *screen_y)
{
	*screen_x = x * norm->scale + norm->offset_x;
	*screen_y = y * norm->scale + norm->offset_y;
}

void	calculate_normalization(t_normalize *norm)
{
	uint32_t	map_width;
	uint32_t	map_height;
	float		scale_x;
	float		scale_y;

	map_width = norm->max_x - norm->min_x;
	map_height = norm->max_y - norm->min_y;
	if (map_width == 0) /* if same x */
		map_width = 1;
	if (map_height == 0) /* if same y */
		map_height = 1;

	scale_x = (WINDOW_WIDTH - 2 * PADDING - 2 * CIRCLE_RADIUS) / map_width;
	scale_y = (WINDOW_HEIGHT - 2 * PADDING - 2 * CIRCLE_RADIUS) / map_height;
	norm->scale = (scale_x < scale_y) ? scale_x : scale_y;
	norm->offset_x = PADDING + CIRCLE_RADIUS - norm->min_x * norm->scale;
	norm->offset_y = PADDING + CIRCLE_RADIUS - norm->min_y * norm->scale;
}

void	calculate_map_limits(t_normalize *norm, uint32_t x, uint32_t y)
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
