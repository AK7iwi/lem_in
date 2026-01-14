#include "lem_in.h"

//refacto 
static	bool	draw_thick_line(SDL_Renderer *renderer,
								float x1, float y1,
								float x2, float y2, float thickness,
								uint8_t r, uint8_t g, uint8_t b)
{
	SDL_Vertex	vertices[4];
	float		dx, dy, length, perp_x, perp_y;
	int			indices[6] = {0, 1, 2, 2, 3, 0};
	int			i;

	dx = x2 - x1;
	dy = y2 - y1;
	length = ft_sqrt(dx * dx + dy * dy);
		
	perp_x = -dy / length * (thickness / 2.0f);
	perp_y = dx / length * (thickness / 2.0f);
	
	vertices[0].position.x = x1 - perp_x;
	vertices[0].position.y = y1 - perp_y;
	vertices[1].position.x = x2 - perp_x;
	vertices[1].position.y = y2 - perp_y;
	vertices[2].position.x = x2 + perp_x;
	vertices[2].position.y = y2 + perp_y;
	vertices[3].position.x = x1 + perp_x;
	vertices[3].position.y = y1 + perp_y;
	
	i = 0;
	while (i < 4)
	{
		vertices[i].color.r = r / 255.0f;
		vertices[i].color.g = g / 255.0f;
		vertices[i].color.b = b / 255.0f;
		vertices[i].color.a = 255;
		vertices[i].tex_coord.x = 0;
		vertices[i].tex_coord.y = 0;
		i++;
	}
	
	return (!SDL_RenderGeometry(renderer, NULL, vertices, 4, indices, 6));
}

static	bool	draw_corridor(SDL_Renderer *renderer,
							  float x1, float y1,
							  float x2, float y2,
							  float radius)
{
	float	corridor_width, border_width;
	float	dx, dy, length, perp_x, perp_y, offset;

	corridor_width = radius * 0.25f;
	border_width = radius * 0.05f;

	dx = x2 - x1;
	dy = y2 - y1;
	length = ft_sqrt(dx * dx + dy * dy);
	
	perp_x = -dy / length;
	perp_y = dx / length;
	
	if (draw_thick_line(renderer, x1, y1, x2, y2,
		corridor_width, 100, 100, 100))
		return (1);
	
	offset = (corridor_width / 2.0f) + (border_width / 2.0f);
	if (draw_thick_line(renderer,
		x1 - perp_x * offset, y1 - perp_y * offset,
		x2 - perp_x * offset, y2 - perp_y * offset,
		border_width, 30, 144, 255))
		return (1);
	
	if (draw_thick_line(renderer,
		x1 + perp_x * offset, y1 + perp_y * offset,
		x2 + perp_x * offset, y2 + perp_y * offset,
		border_width, 30, 144, 255))
		return (1);
	
	return (0);
}

static	void	calculate_line_endpoints(float x1, float y1, float x2, float y2,
									 	 float *start_x, float *start_y, float *end_x, float *end_y,
									 	 float radius)
{
	float	dx, dy;
	float	distance, ratio;

	dx = x2 - x1;
	dy = y2 - y1;
	distance = ft_sqrt(dx * dx + dy * dy);

	ratio = radius / distance;
	*start_x = x1 + dx * ratio;
	*start_y = y1 + dy * ratio;
	*end_x = x2 - dx * ratio;
	*end_y = y2 - dy * ratio;
}

bool	draw_links(t_normalize *norm, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y)
{
	t_link	*link;
	float	x2, y2;
	float	start_x, start_y, end_x, end_y;

	link = room->link;
	while (link)
	{
		if (room < link->room)
		{
			transform_coords(norm, link->room->x, &x2, link->room->y, &y2);
			calculate_line_endpoints(screen_x, screen_y, x2, y2, &start_x, &start_y, &end_x, &end_y, norm->radius);
			if (draw_corridor(renderer, start_x, start_y, end_x, end_y, norm->radius))
				return (1);
		}
		link = link->next;
	}
	
	return (0);
}
