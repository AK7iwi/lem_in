#include "lem_in.h"

void	calculate_normalization(t_data *data, t_normalize *norm)
{
	size_t	i;
	float	map_width;
	float	map_height;
	float	scale_x;
	float	scale_y;

	if (!data->map || data->map->nb_rooms == 0)
		return;

	// Find min and max coordinates
	norm->min_x = (float)data->map->rooms[0].x;
	norm->max_x = (float)data->map->rooms[0].x;
	norm->min_y = (float)data->map->rooms[0].y;
	norm->max_y = (float)data->map->rooms[0].y;

	i = 1;
	while (i < data->map->nb_rooms)
	{
		if (data->map->rooms[i].x < norm->min_x)
			norm->min_x = (float)data->map->rooms[i].x;
		if (data->map->rooms[i].x > norm->max_x)
			norm->max_x = (float)data->map->rooms[i].x;
		if (data->map->rooms[i].y < norm->min_y)
			norm->min_y = (float)data->map->rooms[i].y;
		if (data->map->rooms[i].y > norm->max_y)
			norm->max_y = (float)data->map->rooms[i].y;
		i++;
	}

	// Calculate map dimensions
	map_width = norm->max_x - norm->min_x;
	map_height = norm->max_y - norm->min_y;

	// Handle edge case: all rooms at same position
	if (map_width < 1.0f)
		map_width = 1.0f;
	if (map_height < 1.0f)
		map_height = 1.0f;

	// Calculate scale to fit window with padding
	scale_x = (WINDOW_WIDTH - 2 * PADDING - 2 * CIRCLE_RADIUS) / map_width;
	scale_y = (WINDOW_HEIGHT - 2 * PADDING - 2 * CIRCLE_RADIUS) / map_height;

	// Use the smaller scale to maintain aspect ratio
	norm->scale = (scale_x < scale_y) ? scale_x : scale_y;

	// Calculate offsets to center the map
	norm->offset_x = PADDING + CIRCLE_RADIUS - norm->min_x * norm->scale;
	norm->offset_y = PADDING + CIRCLE_RADIUS - norm->min_y * norm->scale;
}

int	normalize_x(uint32_t x, t_normalize *norm)
{
	return ((int)(x * norm->scale + norm->offset_x));
}

int	normalize_y(uint32_t y, t_normalize *norm)
{
	return ((int)(y * norm->scale + norm->offset_y));
}
