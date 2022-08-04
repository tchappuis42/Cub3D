#include "game/game.h"
#include "../../../../mlx/mlx.h"
#include <stdlib.h>

// manage all the different event of the game window
void window_event_management(t_mlx *mlx)
{
	resize_window(mlx);
	exit_window(mlx);
}

// enable the window to be resized
void resize_window(t_mlx *mlx)
{
	(void)mlx;
	//mlx_expose_hook()
	//mlx_hook(mlx->win, RESIZEREQUEST, 0, how_to_resizing_window, NULL);
}

int exit_game(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESCAPE)
	{
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int exit_game2(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
// enable the window to close with ESC or by clicking on the red cross 
void exit_window(t_mlx *mlx)
{

	mlx_hook(mlx->win, KEYPRESS, 0, exit_game, NULL);
	mlx_hook(mlx->win, DESTROYNOTIFY, 0, exit_game2, NULL);
}
