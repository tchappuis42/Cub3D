
#include "game/game.h"
#include "game/camera.h"
#include "../../../mlx/mlx.h"

//	This function start the game after initialize the graphic library
void game_start(t_data *data, t_tex *tex)
{
	t_game game_info;

	init_game_info(&game_info, data);
	init_sprit(&game_info, tex);
	game_loop(&game_info);
}

// Routine of the game execute the events and the frame management
void game_loop(t_game *game_info)
{
	game_event(game_info);
	//new_frame(game_info);
	mlx_loop_hook(game_info->mlx.ptr, new_frame, game_info);
	mlx_loop(game_info->mlx.ptr);
}

// lanch all the different event
void game_event(t_game *game_info)
{
	window_event_management(&game_info->mlx);
	keyboard_event_management(game_info);
	custom_event_management(game_info);
}