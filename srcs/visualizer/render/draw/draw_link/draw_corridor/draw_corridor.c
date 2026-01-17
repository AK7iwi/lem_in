#include "lem_in.h"

static	void	set_vertex_attributes(SDL_Vertex *vertices, uint8_t r, uint8_t g, uint8_t b)
{
	size_t	i = 0;

	while (i < 4)
	{
		vertices[i].color.r = r / 255.0f;
		vertices[i].color.g = g / 255.0f;
		vertices[i].color.b = b / 255.0f;
		vertices[i].color.a = 1.0f;
		vertices[i].tex_coord.x = 0;
		vertices[i].tex_coord.y = 0;
		i++;
	}
}

static	void	set_vertex_positions(SDL_Vertex *vertices, float x1, float y1,
								 	 float x2, float y2, float perp_x, float perp_y)
{
	vertices[0].position.x = x1 - perp_x;
	vertices[0].position.y = y1 - perp_y;
	vertices[1].position.x = x2 - perp_x;
	vertices[1].position.y = y2 - perp_y;
	vertices[2].position.x = x2 + perp_x;
	vertices[2].position.y = y2 + perp_y;
	vertices[3].position.x = x1 + perp_x;
	vertices[3].position.y = y1 + perp_y;
}

static	bool	draw_thick_line(SDL_Renderer *renderer,
								float x1, float y1,
								float x2, float y2,
								float thickness,
								float perp_x, float perp_y,
								uint8_t r, uint8_t g, uint8_t b)
{
	SDL_Vertex	vertices[4];
	int			indices[6] = {0, 1, 2, 2, 3, 0};

	perp_x *= (thickness / 2.0f);
	perp_y *= (thickness / 2.0f);
	set_vertex_positions(vertices, x1, y1, x2, y2, perp_x, perp_y);
	set_vertex_attributes(vertices, r, g, b);
	
	return (!SDL_RenderGeometry(renderer, NULL, vertices, 4, indices, 6));
}

bool	draw_corridor(SDL_Renderer *renderer,
					  float x1, float y1,
					  float x2, float y2,
					  float radius,
					  float perp_x, float perp_y)
{
	float	corridor_width, border_width, offset;

	corridor_width = radius * 0.25f;
	border_width = radius * 0.05f;
	offset = (corridor_width / 2.0f) + (border_width / 2.0f);
	
	return (draw_thick_line(renderer, x1, y1, x2, y2, corridor_width, perp_x, perp_y, 100, 100, 100)
			|| draw_thick_line(renderer, x1 - perp_x * offset, y1 - perp_y * offset, x2 - perp_x * offset, y2 - perp_y * offset, border_width, perp_x, perp_y, 30, 144, 255)
			|| draw_thick_line(renderer, x1 + perp_x * offset, y1 + perp_y * offset, x2 + perp_x * offset, y2 + perp_y * offset, border_width, perp_x, perp_y, 30, 144, 255));
}
