
#include "game/game.h"
#include "../../../mlx/mlx.h"

//	This function start the game after initialize the graphic library
void game_start(void)
{
	t_mlx mlx;

	graphic_lib_init(&mlx);
	game_loop(&mlx);
}

// Routine of the game execute the events and the frame management
void game_loop(t_mlx *mlx)
{
	game_event(mlx);
	new_frame(mlx);
	mlx_loop(mlx);
}

// lanch all the different event
void game_event(t_mlx *mlx)
{
	window_event_management(mlx);
	keyboard_event_management(mlx);
	custom_event_management(mlx);
}