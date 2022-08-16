RED		= \033[1;31m
YEL		= \033[1;33m
BLU		= \033[1;34m
WHITE	= \033[1;37m
GREEN	= \033[1;32m
RESET	= \033[0m

NAME 	:= Cub3d
CC 		:= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_INC) -g3 -fsanitize=address

SRC_DIR := ./src/
OBJ_DIR	:= ./obj/
OBJ_SUBDIR :=	./obj/game\
				./obj/parsing\
				./obj/game/graphics\
				./obj/game/event

INC_DIR := ./includes

SRC 	:=	main.c\
			parsing/parsing.c\
			parsing/parsing_info.c\
			parsing/parsing_map.c\
			parsing/parsing_texture.c\
			parsing/chek_info.c\
			parsing/color.c\
			parsing/exit_map.c\
			game/game.c\
			game/texture.c\
			game/event/event.c\
			game/event/movement.c\
			game/graphics/raycasting.c\
			game/graphics/screen.c\
			game/camera.c\
			game/utils.c\
			game/graphics/frame.c\
			game/minimap.c\
			game/clean.c


SRCS 	:= $(addprefix  $(SRC_DIR), $(SRC))

OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJ_DIR), $(OBJ))


LIBFT_DIR = libft
LIBFT = libft/libft.a
LIBFT_INC = libft/includes
LIBFT_LIB = -L $(LIBFT_DIR)

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)
MLX_LIB =  -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all:   $(NAME)
$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	@printf "$(YEL)------------Compiling----------------\n$(RESET)"
	@printf "$(RESET)$(CC) $(CFLAGS)\n"
	@$(CC) $(CFLAGS) -I $(MLX_DIR)/mlx.h -o $@ $(OBJS) $(LIBFT) $(MLX_LIB)
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
	@printf "$(RED)CLEANING: $(RESET)\n$(RESET)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C ./$(LIBFT_DIR) clean
	@make -C ./$(MLX_DIR) clean
	@printf "$(RED)removing: $(RESET) $(OBJ_DIR)\n$(RESET)"

fclean:
	@printf "$(RED)CLEANING: $(RESET) \n$(RESET)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C ./$(LIBFT_DIR) fclean
	@make -C ./$(MLX_DIR) clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) removing: $(RESET) $(NAME)\n"

re: fclean all
.PHONY: re fclean clean all

