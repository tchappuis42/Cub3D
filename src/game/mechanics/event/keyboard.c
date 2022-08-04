#include "game/game.h"

// manage all the different event triggered by the keyboard
void keyboard_event_management(t_mlx *mlx)
{
	movement_of_the_character(mlx);
	movement_of_the_camera(mlx);
}

// enable the movement of the character by pressing WASD
void movement_of_the_character(t_mlx *mlx)
{
	(void)mlx;
}

// enable the movement of the camera by pressing ← → ↑ ↓
void movement_of_the_camera(t_mlx *mlx)
{
	(void)mlx;
}
