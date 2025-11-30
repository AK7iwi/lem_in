#include "lem_in.h"

#define MAX_WIDTH 120
#define MAX_HEIGHT 40

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

typedef struct s_canvas
{
	char		grid[MAX_HEIGHT][MAX_WIDTH];
	int			width;
	int			height;
	uint32_t	min_x;
	uint32_t	min_y;
	uint32_t	max_x;
	uint32_t	max_y;
}	t_canvas;

static void	init_canvas(t_canvas *canvas, t_map *map)
{
	int	i, j;
	
	// Find bounding box
	canvas->min_x = map->rooms[0].x;
	canvas->max_x = map->rooms[0].x;
	canvas->min_y = map->rooms[0].y;
	canvas->max_y = map->rooms[0].y;
	
	for (size_t k = 1; k < map->nb_rooms; k++)
	{
		if (map->rooms[k].x < canvas->min_x)
			canvas->min_x = map->rooms[k].x;
		if (map->rooms[k].x > canvas->max_x)
			canvas->max_x = map->rooms[k].x;
		if (map->rooms[k].y < canvas->min_y)
			canvas->min_y = map->rooms[k].y;
		if (map->rooms[k].y > canvas->max_y)
			canvas->max_y = map->rooms[k].y;
	}
	
	// Add padding
	int range_x = canvas->max_x - canvas->min_x;
	int range_y = canvas->max_y - canvas->min_y;
	if (range_x == 0)
		range_x = 1;
	if (range_y == 0)
		range_y = 1;
	
	// Scale to fit canvas
	double scale_x = (double)(MAX_WIDTH - 20) / range_x;
	double scale_y = (double)(MAX_HEIGHT - 10) / range_y;
	double scale = (scale_x < scale_y) ? scale_x : scale_y;
	
	canvas->width = (int)(range_x * scale) + 20;
	canvas->height = (int)(range_y * scale) + 10;
	if (canvas->width > MAX_WIDTH)
		canvas->width = MAX_WIDTH;
	if (canvas->height > MAX_HEIGHT)
		canvas->height = MAX_HEIGHT;
	
	// Initialize grid with spaces
	for (i = 0; i < canvas->height; i++)
	{
		for (j = 0; j < canvas->width; j++)
			canvas->grid[i][j] = ' ';
	}
}

static int	scale_x(t_canvas *canvas, uint16_t x)
{
	int range_x = canvas->max_x - canvas->min_x;
	if (range_x == 0)
		return (canvas->width / 2);
	double scale = (double)(canvas->width - 20) / range_x;
	return ((int)((x - canvas->min_x) * scale) + 10);
}

static int	scale_y(t_canvas *canvas, uint16_t y)
{
	int range_y = canvas->max_y - canvas->min_y;
	if (range_y == 0)
		return (canvas->height / 2);
	double scale = (double)(canvas->height - 10) / range_y;
	return ((int)((y - canvas->min_y) * scale) + 5);
}

static void	draw_line(t_canvas *canvas, int x1, int y1, int x2, int y2)
{
	int	dx = x2 - x1;
	int	dy = y2 - y1;
	int	steps = (ft_abs(dx) > ft_abs(dy)) ? ft_abs(dx) : ft_abs(dy);
	int	i;
	
	if (steps == 0)
		return;
	
	for (i = 0; i <= steps; i++)
	{
		int x = x1 + (dx * i) / steps;
		int y = y1 + (dy * i) / steps;
		
		if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height)
		{
			char c = ' ';
			if (dx == 0)
				c = '|';
			else if (dy == 0)
				c = '-';
			else if ((dx > 0 && dy > 0) || (dx < 0 && dy < 0))
				c = '\\';
			else
				c = '/';
			
			// Don't overwrite room names (letters, brackets)
			if (canvas->grid[y][x] == ' ' || canvas->grid[y][x] == c || 
				canvas->grid[y][x] == '|' || canvas->grid[y][x] == '-' ||
				canvas->grid[y][x] == '\\' || canvas->grid[y][x] == '/' ||
				canvas->grid[y][x] == '+')
			{
				if (canvas->grid[y][x] != ' ' && canvas->grid[y][x] != c)
					canvas->grid[y][x] = '+';
				else
					canvas->grid[y][x] = c;
			}
		}
	}
}

static void	draw_connections(t_canvas *canvas, t_map *map)
{
	size_t		i;
	t_link	*current_link;
	t_room		*room1;
	t_room		*room2;
	
	i = 0;
	while (i < map->nb_rooms)
	{
		room1 = &map->rooms[i];
		current_link = room1->link;
		
		while (current_link)
		{
			room2 = current_link->room;
			if (room2 > room1)
			{
				int x1 = scale_x(canvas, room1->x);
				int y1 = scale_y(canvas, room1->y);
				int x2 = scale_x(canvas, room2->x);
				int y2 = scale_y(canvas, room2->y);
				draw_line(canvas, x1, y1, x2, y2);
			}
			current_link = current_link->next;
		}
		i++;
	}
}

static void	draw_room(t_canvas *canvas, t_room *room, int x, int y)
{
	int	i;
	int	name_len = 0;
	
	while (room->name[name_len])
		name_len++;
	
	// Draw room as [name]
	if (x >= 0 && x + name_len + 2 < canvas->width && y >= 0 && y < canvas->height)
	{
		canvas->grid[y][x] = '[';
		for (i = 0; i < name_len && x + 1 + i < canvas->width; i++)
			canvas->grid[y][x + 1 + i] = room->name[i];
		if (x + 1 + name_len < canvas->width)
			canvas->grid[y][x + 1 + name_len] = ']';
	}
}

static void	draw_rooms(t_canvas *canvas, t_map *map)
{
	size_t	i;
	int		x, y;
	
	i = 0;
	while (i < map->nb_rooms)
	{
		x = scale_x(canvas, map->rooms[i].x);
		y = scale_y(canvas, map->rooms[i].y);
		draw_room(canvas, &map->rooms[i], x, y);
		i++;
	}
}

static void	print_canvas(t_canvas *canvas)
{
	int	i, j;
	
	for (i = 0; i < canvas->height; i++)
	{
		for (j = 0; j < canvas->width; j++)
			ft_putchar(canvas->grid[i][j], STDOUT_FILENO);
		ft_putchar('\n', STDOUT_FILENO);
	}
}

bool	print_map(t_data *data) //display_map
{
	t_canvas	canvas;

	init_canvas(&canvas, data->map);
	draw_connections(&canvas, data->map);
	draw_rooms(&canvas, data->map);
	
	ft_putstr("\n", STDOUT_FILENO);
	print_canvas(&canvas);
	ft_putstr("\n", STDOUT_FILENO);
	
	return (true);
}