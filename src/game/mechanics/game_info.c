# include "game/game.h"
#include "game/struct.h"
# include "../../../mlx/mlx.h"

// Initialize the main structure
void init_game_info(t_game *game_info, t_data *map)
{
	game_info->map = map;
	init_camera(&game_info->camera, map->px, map->py);
	init_graphic_lib(game_info);
}

// init the graphic lib and create the game window
void init_graphic_lib(t_game *game_info)
{
	game_info->mlx.ptr = mlx_init();
	game_info->mlx.win = mlx_new_window(game_info->mlx.ptr, 1080, 720, "Cub3d");
}