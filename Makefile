NAME			:= lem-in

SRC_DIR			:= srcs
OBJ_DIR			:= obj

SRCS			:=	main.c \
					init/init.c \
					init/init_struct/init_nb_ants.c init/init_struct/init_room.c init/init_struct/init_link.c \
					errors/display_errors.c \
					parser/parser.c parser/parse_data/parse_data.c \
					parser/parse_data/parse_line/parse_line_type.c \
					parser/parse_data/parse_line/parse_ants/parse_ants.c \
					parser/parse_data/parse_line/parse_command_ant_comment/parse_command_ant_comment.c \
					parser/parser_data/parse_line/parse_room/parse_room.c \
					parser/parser_data/parser_line/parse_link/parse_link.c \
					parser/parse_data/bfs_algo/bfs.c \
					parser/parse_data/tools/parse_data_tools.c \
					displayer/print_general_infos.c displayer/print_map.c \
					tools/get_next_line/srcs/get_next_line.c tools/get_next_line/srcs/utils/utils.c \
					tools/print/print.c \
					tools/check_type/check_type.c \
					tools/convert_type/ft_atoi.c \
					tools/free/free_data.c
SRCS        	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS        	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS    	:= -I includes -I srcs/tools/get_next_line/includes

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