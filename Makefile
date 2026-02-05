NAME			:= lem-in

SRC_DIR			:= srcs
OBJ_DIR			:= obj

# SDL3 Configuration
SDL3_DIR			:= $(SRC_DIR)/visualizer/SDL
SDL3_BUILD_DIR		:= $(SDL3_DIR)/build
SDL3_LIB			:= $(SDL3_BUILD_DIR)/libSDL3.a

SRCS			:=	main.c \
					init/init.c \
					parser/parser.c \
					parser/parse_arg/validate_arg.c \
					parser/parse_data/parse_data.c \
					parser/parse_data/parse_map/parse_map.c \
					parser/parse_data/parse_map/parse_ants/parse_ants.c \
					parser/parse_data/parse_map/parse_ants/validate/validate_ants.c \
					parser/parse_data/parse_map/parse_ants/validate/format/validate_ants_format.c \
					parser/parse_data/parse_map/parse_ants/validate/extract/extract_ants.c \
					parser/parse_data/parse_map/parse_ants/validate/extract/tools/ft_atoi.c \
					parser/parse_data/parse_map/parse_ants/validate/value/validate_ants_value.c \
					parser/parse_data/parse_map/parse_ants/create/create_ants.c parser/parse_data/parse_map/parse_ants/create/set_start_room.c \
					parser/parse_data/parse_map/parse_cmd_and_cmt/parse_cmd_and_cmt.c \
					parser/parse_data/parse_map/parse_cmd_and_cmt/validate/validate_cmd_and_cmt.c \
					parser/parse_data/parse_map/parse_cmd_and_cmt/validate/format/validate_cmd_and_cmt_format.c \
					parser/parse_data/parse_map/parse_cmd_and_cmt/validate/value/validate_cmd_and_cmt_value.c \
					parser/parse_data/parse_map/parse_cmd_and_cmt/create/create_cmd.c \
					parser/parse_data/parse_map/parse_room/parse_room.c \
					parser/parse_data/parse_map/parse_room/validate/validate_room.c \
					parser/parse_data/parse_map/parse_room/validate/format/validate_room_format.c \
					parser/parse_data/parse_map/parse_room/validate/extract/extract_room.c \
					parser/parse_data/parse_map/parse_room/validate/value/validate_room_values.c \
					parser/parse_data/parse_map/parse_room/create/create_room.c \
					parser/parse_data/parse_map/parse_link/parse_link.c \
					parser/parse_data/parse_map/parse_link/validate/validate_link.c \
					parser/parse_data/parse_map/parse_link/validate/format/validate_link_format.c \
					parser/parse_data/parse_map/parse_link/validate/extract/extract_link.c \
					parser/parse_data/parse_map/parse_link/validate/value/validate_link_values.c \
					parser/parse_data/parse_map/parse_link/create/create_link.c \
					parser/parse_data/parse_map/parse_link/tools/free_rooms.c \
					parser/parse_data/parse_map/common/validate/validate_data.c \
					parser/parse_data/parse_map/common/validate/tools/check_char_type.c \
					parser/parse_data/parse_map/common/extract/extract_data.c \
					parser/parse_data/parse_map/tools/get_next_line/srcs/get_next_line.c parser/parse_data/parse_map/tools/get_next_line/srcs/utils/utils.c \
					parser/parse_data/parse_map/tools/empty_line.c parser/parse_data/parse_map/tools/skip_space_char.c parser/parse_data/parse_map/tools/last_char.c \
					parser/parse_data/validate_map/validate_map.c \
					ant_colony/ant_colony.c \
					ant_colony/init/init_pathset.c \
					ant_colony/pathfinding/dinic_algo.c \
					ant_colony/pathfinding/init/init_algo.c \
					ant_colony/pathfinding/bfs/bfs.c \
					ant_colony/pathfinding/store/store_path.c \
					ant_colony/pathfinding/tools/free_arrays.c ant_colony/pathfinding/tools/room_index.c ant_colony/pathfinding/tools/reset_arrays.c \
					ant_colony/free/free_pathset.c \
					visualizer/visualizer.c \
					visualizer/params/map_metrics.c visualizer/params/set_params.c \
					visualizer/render/init_render.c visualizer/render/render.c visualizer/render/close_render.c \
					visualizer/render/event/event_handler.c \
					visualizer/render/event/quit/quit.c \
					visualizer/render/event/key/key.c \
					visualizer/render/event/zoom/zoom.c \
					visualizer/render/event/drag/drag.c \
					visualizer/render/draw/draw_render.c \
					visualizer/render/draw/transform/coord_transform.c \
					visualizer/render/draw/draw_room/draw_room.c \
					visualizer/render/draw/draw_room/set_room/set_room.c \
					visualizer/render/draw/draw_room/draw_circle/draw_circle.c \
					visualizer/render/draw/draw_room/draw_name/draw_name.c \
					visualizer/render/draw/draw_link/draw_link.c \
					visualizer/render/draw/draw_link/set_corridor/set_corridor.c \
					visualizer/render/draw/draw_link/draw_corridor/draw_corridor.c \
					visualizer/tools/ft_sqrt.c \
					displayer/infos/display_infos.c \
					displayer/infos/display_room/display_room.c \
					displayer/infos/display_link/display_link.c \
					displayer/errors/display_errors.c \
					displayer/errors/gen/gen_error.c \
					displayer/errors/parsing/parsing_error.c \
					displayer/errors/visu/visu_error.c \
					displayer/tools/print.c \
					free/free_data.c
SRCS        	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS        	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS    	:= -I includes -I srcs/parser/parse_data/parse_map/tools/get_next_line/includes -I $(SDL3_DIR)/include
LDFLAGS			:= -L$(SDL3_BUILD_DIR) -lSDL3 -lm -lpthread -ldl -lrt

RM				:= rm -rf
DIR_DUP     	= mkdir -p $(@D)

# Color
DEF_COLOR	= \033[0;39m
RED 		= \033[0;36m

all: $(NAME)
	@clear
	@echo "$(RED)lem_in ready$(DEF_COLOR)"

# Build SDL3 library
$(SDL3_LIB):
	@echo "$(RED)Building SDL3...$(DEF_COLOR)"
	@mkdir -p $(SDL3_BUILD_DIR)
	@cd $(SDL3_BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=OFF -DSDL_STATIC=ON
	@cd $(SDL3_BUILD_DIR) && cmake --build . -j$$(nproc)
	@echo "$(RED)SDL3 built$(DEF_COLOR)"

$(NAME): $(SDL3_LIB) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)
	@clear
	@echo "$(RED)lem_in objects cleaned$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SDL3_BUILD_DIR)
	@echo "$(RED)lem_in cleaned$(DEF_COLOR)"

re:	fclean all
	@echo "$(RED)lem_in cleaned and rebuilt$(DEF_COLOR)"

test: all
	@./map_tester/test_maps.sh || true

.PHONY: all clean fclean re test