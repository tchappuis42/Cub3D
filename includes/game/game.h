#ifndef GAME_H
#define GAME_H

#include "game/struct.h"
#include "game/camera.h"
#include "parsing/parsing.h"

#define TEXWIDTH 736
#define TEXHEIGHT 736
#define WIDTH 1000
#define HEIGHT 1000

#define YELLOW 0XF2FF00
#define CEILING 0x00ff00
#define FLOOR 0x00ffff

typedef struct s_game
{
	t_mlx		mlx;
	t_data		*map;
	t_camera	camera;
	int			*buffer;
	int			**texture;
}t_game;

void		game_start(t_data *map, t_tex *tex);
void		init_info(t_game *info, t_data *map, t_tex *tex);
void		main_loop(t_game *info);
void	game_event(t_game *info);
int		keypress_event(int keycode, void *param);
int	generate_screen(void *param);
int		ft_exit(void *param);
void generate_texture(t_game *info, t_tex *tex);
void create_texture_image(char *path, t_game *info, int i);
int	ft_exit(void *param);
void ft_clean(t_game* info);
void	minimap(t_mlx *mlx, t_data *map, t_camera *cam);
int *new_texture(void);
void get_texture(int *src, int *dst);
void free_buffer(t_game *info);
void free_texture(t_game *info);



#endif