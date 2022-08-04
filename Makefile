RED		= \033[1;31m
YEL		= \033[1;33m
BLU		= \033[1;34m
WHITE	= \033[1;37m
GREEN	= \033[1;32m
RESET	= \033[0m

NAME 	:= Cub3d
CC 		:= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(INC_DIR) -I $(MLX_INC)

SRC_DIR := ./src/
OBJ_DIR	:= ./obj/
OBJ_SUBDIR :=	./obj/game\
				./obj/game/graphic\
				./obj/game/mechanics\
				./obj/game/mechanics/event

INC_DIR := ./includes

SRC 	:=	main.c\
			game/mechanics/game.c\
			game/mechanics/init.c\
			game/mechanics/event/custom.c\
			game/mechanics/event/keyboard.c\
			game/mechanics/event/window.c\
			parsing/parsing.c\
			parsing/parsing_info.c\
			parsing/parsing_map.c\
			parsing/chek_info.c\

SRCS 	:= $(addprefix  $(SRC_DIR), $(SRC))

OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJ_DIR), $(OBJ))


LIBFT_DIR = libft
LIBFT_INC = libft/includes
LIBFT_LIB = -L $(LIBFT_DIR)

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)
MLX_LIB =  -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all:   $(NAME)
$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	@printf "$(YEL)\n------------Compiling----------------\n$(RESET)"
	@printf "$(RESET)$(CC) $(CFLAGS)\n"
	@$(CC) $(CFLAGS) -I $(MLX_DIR)/mlx.h -o $@ $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@printf "$(YEL)------------Linked------------------\n$(RESET)"
	@printf "$(GREEN)$(NAME) sucessfully created ! $(RESET)\n"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -o $@ -c $(subst obj/, $(SRC_DIR), $*).c

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_SUBDIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C ./$(LIBFT_DIR) clean
	@make -C ./$(MLX_DIR) clean
	@printf "\n $(RED)removing: $(RESET) $(OBJ_DIR)\n$(RESET)"

fclean: clean
	@make -C ./$(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@printf "\n $(RED)removing: $(RESET) $(NAME)\n"

re: fclean all
.PHONY: re fclean clean all

