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
					parser/parse_data/tools/get_next_line/srcs/get_next_line.c parser/parse_data/tools/get_next_line/srcs/utils/utils.c \
					parser/parse_data/parse_line/parse_line.c \
					parser/parse_data/parse_line/tools/empty_line.c parser/parse_data/parse_line/tools/skip_space_char.c parser/parse_data/parse_line/tools/last_char.c \
					parser/parse_data/parse_line/parsers/parse_ants/parse_ants.c \
					parser/parse_data/parse_line/parsers/parse_ants/validate/validate_ants.c parser/parse_data/parse_line/parsers/parse_ants/validate/validate_ants_format.c parser/parse_data/parse_line/parsers/parse_ants/validate/validate_ants_value.c \
					parser/parse_data/parse_line/parsers/parse_ants/extract/extract_ants.c \
					parser/parse_data/parse_line/parsers/parse_ants/create/create_ants.c parser/parse_data/parse_line/parsers/parse_ants/create/set_start_room.c \
					parser/parse_data/parse_line/parsers/parse_ants/tools/ft_atoi.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/parse_cmd_and_cmt.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt.c parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt_format.c parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt_value.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/create/create_cmd.c \
					parser/parse_data/parse_line/parsers/parse_room/parse_room.c \
					parser/parse_data/parse_line/parsers/parse_room/validate/validate_room.c parser/parse_data/parse_line/parsers/parse_room/validate/validate_room_format.c parser/parse_data/parse_line/parsers/parse_room/validate/validate_room_values.c \
					parser/parse_data/parse_line/parsers/parse_room/extract/extract_room.c \
					parser/parse_data/parse_line/parsers/parse_room/create/create_room.c \
					parser/parse_data/parse_line/parsers/parse_link/parse_link.c \
					parser/parse_data/parse_line/parsers/parse_link/validate/validate_link.c parser/parse_data/parse_line/parsers/parse_link/validate/validate_link_format.c parser/parse_data/parse_line/parsers/parse_link/validate/validate_link_values.c \
					parser/parse_data/parse_line/parsers/parse_link/extract/extract_link.c \
					parser/parse_data/parse_line/parsers/parse_link/create/create_link.c \
					parser/parse_data/parse_line/parsers/parse_link/tools/free_rooms.c \
					parser/parse_data/parse_line/parsers/common/validate/validate_data.c \
					parser/parse_data/parse_line/parsers/common/extract/extract_data.c \
					parser/parse_data/parse_line/parsers/common/tools/check_char_type.c \
					parser/parse_data/bfs_algo/bfs.c \
					parser/parse_data/bfs_algo/tools/free_array.c \
					displayer/display_errors.c displayer/display_infos.c \
					displayer/tools/print.c \
					free/free_data.c \
					visualizer/visualizer.c \
					visualizer/render/init_render.c visualizer/render/render.c visualizer/render/close_render.c \
					visualizer/render/events/event_handler.c \
					visualizer/render/events/quit/quit.c \
					visualizer/render/events/key/key.c \
					visualizer/render/events/zoom/zoom.c \
					visualizer/render/events/drag/drag.c \
					visualizer/render/draw/draw_render.c \
					visualizer/render/draw/draw_rooms/draw_rooms.c \
					visualizer/render/draw/draw_links/draw_links.c \
					visualizer/render/draw/transform/coord_transform.c \
					visualizer/params/map_metrics.c visualizer/params/set_params.c \
					visualizer/tools/ft_sqrt.c 
SRCS        	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS        	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS    	:= -I includes -I srcs/parser/parse_data/tools/get_next_line/includes -I $(SDL3_DIR)/include
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

test: fclean all
	@./map_tester/test_maps.sh || true

.PHONY: all clean fclean re test