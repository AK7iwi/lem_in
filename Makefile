NAME			:= lem-in

SRC_DIR			:= srcs
OBJ_DIR			:= obj

SRCS			:=	main.c \
					init/init.c \
					parser/parser.c \
					parser/parse_arg/validate_arg.c \
					parser/parse_data/parse_data.c \
					parser/parse_data/tools/get_next_line/srcs/get_next_line.c parser/parse_data/tools/get_next_line/srcs/utils/utils.c \
					parser/parse_data/parse_line/parse_line.c \
					parser/parse_data/parse_line/tools/empty_line.c parser/parse_data/parse_line/tools/last_char.c \
					parser/parse_data/parse_line/parsers/parse_ants/parse_ants.c \
					parser/parse_data/parse_line/parsers/parse_ants/validate/validate_ants.c \
					parser/parse_data/parse_line/parsers/parse_ants/create/create_ants.c \
					parser/parse_data/parse_line/parsers/parse_ants/tools/ft_atoi.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/parse_cmd_and_cmt.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/validate/validate_cmd_and_cmt.c \
					parser/parse_data/parse_line/parsers/parse_cmd_and_cmt/create/create_valid_cmd.c \
					parser/parse_data/parse_line/parsers/parse_room/parse_room.c \
					parser/parse_data/parse_line/parsers/parse_room/validate/validate_room.c \
					parser/parse_data/parse_line/parsers/parse_room/extract/extract_room.c \
					parser/parse_data/parse_line/parsers/parse_room/create/create_room.c \
					parser/parse_data/parse_line/parsers/parse_link/parse_link.c \
					parser/parse_data/parse_line/parsers/parse_link/validate/validate_link.c \
					parser/parse_data/parse_line/parsers/parse_link/create/create_link.c \
					parser/parse_data/parse_line/parsers/validate/validate_data.c \
					parser/parse_data/parse_line/parsers/tools/check_char_type.c parser/parse_data/parse_line/parsers/tools/skip_space_char.c \
					parser/parse_data/bfs_algo/bfs.c \
					parser/parse_data/bfs_algo/tools/free_array.c parser/parse_data/bfs_algo/tools/room_index.c \
					displayer/display_errors.c displayer/display_infos.c displayer/display_map.c \
					displayer/tools/print.c \
					free/free_data.c
SRCS        	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS        	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS    	:= -I includes -I srcs/parser/parse_data/tools/get_next_line/includes

RM				:= rm -rf
DIR_DUP     	= mkdir -p $(@D)

# Color
DEF_COLOR	= \033[0;39m
RED 		= \033[0;36m

all: $(NAME)
	@clear
	@echo "$(RED)lem_in ready$(DEF_COLOR)"

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

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
	@echo "$(RED)lem_in cleaned$(DEF_COLOR)"

re:	fclean all
	@echo "$(RED)lem_in cleaned and rebuilt$(DEF_COLOR)"

test:	all
	@./map_tester/test_maps.sh || true

.PHONY: all clean fclean re test