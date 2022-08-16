#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11
CFLAGS+= -w

ECHO	:= echo
GREEN	:= \033[1;32m
RED		:= \033[1;31m
RESET	:= \033[0m

all: $(NOM)

.c.o:
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
.m.o:
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(NOM):	$(OBJ)
	@$(ECHO) "$(GREEN)Minilibx compiled with success!$(RESET)"
	@ar -r -c $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@ $(ECHO) "$(RED)libmlx removing:$(RESET)\n	- objects files\n	- $(NOM)\n$(RESET)"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
