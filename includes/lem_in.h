#ifndef LEM_IN_H
# define LEM_IN_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include "get_next_line.h"
# include <SDL3/SDL.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

/* Visualizer */
# define PADDING 		60

/* Parsing */
# define MAX_ANTS		2000
# define MIN_ANTS		1
# define MAX_ROOMS		10000
# define MAX_COORDINATE MAX_ROOMS * 100

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_normalize
{
	uint16_t	window_width;
	uint16_t	window_height;
	uint32_t	min_x;
	uint32_t	max_x;
	uint32_t	min_y;
	uint32_t	max_y;
	float		scale;
	float		offset_x;
	float		offset_y;
	float		radius;
	float		zoom;
	float		pan_x;
	float		pan_y;
}	t_normalize;

typedef struct s_room	t_room;

typedef struct s_path
{
	t_room		**rooms;
	uint16_t	len;
}	t_path;

typedef struct s_pathset
{
	t_path		*paths;
	uint16_t	nb_paths;
}	t_pathset;

typedef struct s_link
{
	t_room			*room;

	struct s_link	*next;
}	t_link;

typedef struct s_room
{
	char		*name;
	uint32_t	x;
	uint32_t	y;
	bool		is_empty;

	t_link		*link;
}	t_room;

typedef struct s_map
{
	uint16_t	nb_rooms;
	uint16_t	capacity;
	uint16_t	nb_links;
	uint16_t	nb_valid_cmds;
	t_room		*rooms;
	t_room		*start_room;
	t_room		*end_room;
}	t_map;

typedef struct s_ant
{
	uint16_t		id;
	t_room			*current_room;
	bool			has_moved;

	struct s_ant	*next;
}	t_ant;

typedef struct s_data
{
	// uint16_t	moves;
	// uint16_t	time;
	uint16_t	nb_ants;

	t_err		err;
	t_ant		*ant;
	t_map		*map;
	t_normalize	norm;
}	t_data;

//**********************************************//
//												//
//					  FREE		  				//
//												//
//**********************************************//

/* free_data.c */
void		free_data(t_data *data);

//**********************************************//
//												//
//					  DISPLAYER		  			//
//												//
//**********************************************//

/* tools/print.c */
void		ft_putnbr(int n, int fd);
void		ft_putstr(char *str, int fd);
void		ft_putchar(char	c, int fd);

/* infos/display_link/display_link.c */
void		display_links(t_map *map);
/* infos/display_room/display_room.c */
void		display_room(t_room *room);
void		display_rooms(t_map *map);

/* infos/display_infos.c */
void		display_infos(t_data *data);

//**********************************************//
//												//
//					  VISUALIZER		  		//
//												//
//**********************************************//

/* tools/ft_sqrt.c */
float		ft_sqrt(float n);


/* render/draw/draw_link/draw_corridor/draw_corridor.c */
bool		draw_corridor(SDL_Renderer *renderer, float x1, float y1, float x2, float y2, float radius, float perp_x, float perp_y);
/* render/draw/draw_link/set_corridor/set_corridor.c */
void		set_corridor(t_normalize *norm, t_link *link, float screen_x, float screen_y, float *start_x, float *start_y, float *end_x, float *end_y, float *length, float *perp_x, float *perp_y);
/* render/draw/draw_link/draw_link.c */
bool		draw_link(t_normalize *norm, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y);

/* render/draw/draw_room/draw_name/draw_name.c */
bool		draw_name(SDL_Renderer *renderer, char *name, float x, float y);
/* render/draw/draw_room/draw_circle/draw_circle.c */
bool		draw_circle(SDL_Renderer *renderer, float radius, float center_x, float center_y);
/* render/draw/draw_room/set_room/set_room.c */
bool		set_colors(t_map *map, SDL_Renderer *renderer, t_room *room);
/* render/draw/draw_room/draw_room.c */
bool		draw_room(t_data *data, SDL_Renderer *renderer, t_room *room, float screen_x, float screen_y);

/* render/draw/transform/coord_transform.c */
void		transform_coords(t_normalize *norm, uint32_t x, uint32_t y, float *screen_x, float *screen_y);

/* render/draw/draw_render.c */
bool		draw_render(t_data *data, SDL_Renderer *renderer);


/* render/event/drag/drag.c */
void		handle_drag(t_normalize *norm, SDL_Event *event);
/* render/event/zoom/zoom.c */
void		handle_zoom(t_normalize *norm, SDL_Event *event);
/* render/event/key/key.c */
bool		handle_key(t_normalize *norm, SDL_Event *event);
/* render/event/quit/quit.c */
bool		handle_quit(SDL_Event *event);

/* render/event/event_handler.c */
bool		event_handler(t_normalize *norm);


/* render/close_render.c */
void		close_render(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *map_cache);
/* render/render.c */
bool		render(t_data *data, SDL_Renderer *renderer, SDL_Texture *map_cache);
/* render/init_render.c */
bool    	init_render(t_data *data, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **map_cache);


/* params/set_params.c */
void		set_params(t_normalize *norm, uint16_t nb_rooms);
/* params/map_metrics.c */
uint32_t	calculate_map_size(t_normalize *norm, uint32_t *map_width, uint32_t *map_height);
void		get_map_bounds(t_normalize *norm, uint32_t x, uint32_t y);


/* visualizer.c */
bool		visualizer(t_data *data);

//**********************************************//
//												//
//					  ANT_COLONY		  		//
//												//
//**********************************************//



/* free/free_pathset.c */
void		free_pathset(t_pathset *pathset);


/* routing/routing.c */




/* pathfinding/tools/reset_arrays.c */
void		reset_bfs_arrays(t_map *map, bool *visited, t_room **parent, t_room **queue, size_t *queue_front, size_t *queue_back);
/* pathfinding/tools/room_index.c */
size_t		get_room_index(t_map *map, t_room *room);
/* pathfinding/tools/free_arrays.c */
void		free_arrays(t_room **queue, bool *visited, t_room **parent, bool *used_rooms);

/* pathfinding/store/store_path.c */
bool		store_path(t_data *data, t_room **parent, bool *used_rooms, t_pathset *pathset, uint16_t path_idx);

/* pathfinding/bfs/bfs.c */
bool		bfs(t_map *map, bool *visited, bool *used_rooms, t_room **parent, t_room **queue, size_t queue_front, size_t queue_back);

/* pathfinding/init/init_algo.c */
bool		init_algo(t_map *map, t_room ***queue, bool **visited, t_room ***parent, bool **used_rooms, size_t *queue_front, size_t *queue_back);

/* pathfinding/dinic_algo.c */
bool		dinic(t_data *data, t_pathset *pathset);


/* init/init_pathset.c */
bool		init_pathset(t_data *data, t_pathset *pathset);


/* ant_colony.c */
bool    	ant_colony(t_data *data);

//**********************************************//
//												//
//					  PARSER		  			//
//												//
//**********************************************//

/* parse_data/validate_map/validate_map.c */
bool		is_valid_map(t_data *data);


/* parse_data/parse_map/tools/last_char.c */
bool		is_last_char(char c);
/* parse_data/parse_map/tools/skip_space_char.c */
void		skip_space(char	*line, size_t *i);
/* parse_data/parse_map/tools/empty_line.c */
bool		is_empty_line(char *line);


/* parse_data/parse_map/common/extract/extract_data.c */
char		*extract_name(t_err *err, char *line, size_t name_start, size_t name_end);
/* parse_data/parse_map/common/tools/validate/check_char_type.c */
bool		is_alnum(int c);
bool		is_digit(int c);
/* parse_data/parse_map/common/validate/validate_data.c */
t_room		*is_existing_room(t_map *map, char *name);
bool		validate_name(char *line, size_t *name_start, size_t *name_end, size_t *i);
bool		is_valid_number(char *line, size_t *i);


/* parse_data/parse_map/parse_link/tools/free_rooms.c */
void		free_room_names(char *room1_name, char *room2_name);
/* parse_data/parse_map/parse_link/create/create_link.c */
bool		create_link(t_data *data, t_room *room1, t_room *room2);
/* parse_data/parse_map/parse_link/validate/value/validate_link_values.c */
bool		validate_link_values(t_data *data, t_room **room1, char *room1_name, t_room **room2, char *room2_name);
/* parse_data/parse_map/parse_link/validate/extract/extract_link.c */
bool		extract_room_names(t_err *err, char *line, char **room1_name, size_t room1_start, size_t room1_end, char **room2_name, size_t room2_start, size_t room2_end);
/* parse_data/parse_map/parse_link/validate/format/validate_link_format.c */
bool		validate_link_format(char *line, size_t *room1_start, size_t *room1_end, size_t *room2_start, size_t *room2_end);
/* parse_data/parse_map/parse_link/validate/validate_link.c */
bool		validate_link(t_data *data, char *line, t_room **room1, t_room **room2);
/* parse_data/parse_map/parse_link/parse_link.c */
bool		parse_link(t_data *data, char *line);


/* parse_data/parse_map/parse_room/create/create_room.c */
bool		create_room(t_data	*data, char	*name, uint32_t	x, uint32_t	y, bool	is_start, bool	is_end);
/* parse_data/parse_map/parse_room/validate/value/validate_room_values.c */
bool    	validate_room_values(t_data *data, char *name, uint32_t x, uint32_t y);
/* parse_data/parse_map/parse_room/validate/extract/extract_room.c */
bool		extract_room_data(t_err *err, char *line, char **name, uint32_t *x, uint32_t *y, size_t name_start, size_t name_end, size_t x_start, size_t x_end, size_t y_start, size_t y_end);
/* parse_data/parse_map/parse_room/validate/format/validate_room_format.c */
bool		validate_room_format(char *line, size_t *name_start, size_t *name_end, size_t *x_start, size_t *x_end, size_t *y_start, size_t *y_end);
/* parse_data/parse_map/parse_room/validate/validate_room.c */
bool		validate_nb_rooms(t_map *map);
bool		validate_room(t_data *data, char *line, char **name, uint32_t *x, uint32_t *y);
/* parse_data/parse_map/parse_room/parse_room.c */
bool		parse_room(t_data *data, char *line, bool is_start, bool is_end);


/* parse_data/parse_map/parse_cmd_and_cmt/create/create_cmd.c */
bool		create_cmd(t_data *data, int fd, bool is_start, bool is_end);
/* parse_data/parse_map/parse_cmd_and_cmt/validate/value/validate_cmd_and_cmt_value.c */
bool		validate_cmd_and_cmt_value(t_data *data, bool is_start, bool is_end);
/* parse_data/parse_map/parse_cmd_and_cmt/validate/format/validate_cmd_and_cmt_format.c */
bool		validate_cmd_and_cmt_format(char *line, bool *is_start, bool *is_end);
/* parse_data/parse_map/parse_cmd_and_cmt/validate/validate_cmd_and_cmt.c */
bool		validate_cmd_and_cmt(t_data	*data, char	*line, bool *is_start, bool *is_end);
/* parse_data/parse_map/parse_cmd_and_cmt/parse_cmd_and_cmt.c */
bool		parse_cmd_and_cmt(t_data *data, int fd, char *line);


/* parse_data/parse_map/parse_ants/create/set_start_room.c */
void		set_start_room(t_data *data);
/* parse_data/parse_map/parse_ants/create/create_ants.c */
bool		create_ants(t_data *data, uint16_t nb_ants);
/* parse_data/parse_map/parse_ants/validate/value/validate_ants_value.c */
bool		validate_ants_value(uint16_t nb_ants);
/* parse_data/parse_map/parse_ants/validate/extract/tools/ft_atoi.c */
int			ft_atoi(const char *nptr);
/* parse_data/parse_map/parse_ants/validate/extract/extract_ants.c */
void		extract_nb_ants(char *line, uint16_t *nb_ants);
/* parse_data/parse_map/parse_ants/validate/format/validate_ants_format.c */
bool		validate_ants_format(char *line);
/* parse_data/parse_map/parse_ants/validate/validate_ants.c */
bool		validate_ants(t_err *err, char *line, uint16_t *nb_ants);
/* parse_data/parse_map/parse_ants/parse_ants.c */
bool		parse_ants(t_data *data, char *line);


/* parse_data/parse_map/parse_map.c */
bool		parse_map(t_data *data, int fd);


/* parse_data/parse_data.c */
bool		parse_data(t_data *data, int fd);


/* parse_arg/validate_arg.c */
bool		has_no_arg(int argc);


/* parser.c */
bool		parser(t_data *data, int fd, int argc);

//**********************************************//
//												//
//					  INIT		  				//
//												//
//**********************************************// 

/* init.c */
bool	init(t_data *data, char **argv);

#endif /* LEM_IN_H */
