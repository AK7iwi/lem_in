#include "lem_in.h"

//chane order of params
void	transform_coords(t_normalize *norm, uint32_t x, float *screen_x, uint32_t y, float *screen_y)
{
	*screen_x = x * norm->scale + norm->offset_x + norm->pan_x / norm->zoom;
	*screen_y = y * norm->scale + norm->offset_y + norm->pan_y / norm->zoom;
}