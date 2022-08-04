# include "game/game.h"
# include "../../../mlx/mlx.h"

// init the graphic lib and create the game window
void graphic_lib_init(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 1080, 720, "Cub3d");
}