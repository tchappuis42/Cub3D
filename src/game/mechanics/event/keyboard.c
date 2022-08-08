#include "game/game.h"
#include "../../../../mlx/mlx.h"
#include <math.h>
// manage all the different event triggered by the keyboard
void keyboard_event_management(t_game *game_info)
{
	movement_of_the_character(game_info);
	movement_of_the_camera(game_info);
}

int movement(int keycode, void *param)
{
	t_game *game_info;

	game_info = (t_game *)param;
	double movespeed = 0.3;
	if (keycode == KEY_ESCAPE)
	{
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_A ||
		keycode == KEY_W||
		keycode == KEY_S ||
		keycode == KEY_D ||
		keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
	if (keycode == KEY_W)
	{
		if (game_info->map->map[(int)(game_info->camera.posY + game_info->camera.playerDirectionY)][(int)game_info->camera.posX] == '0')
		{
			game_info->camera.posY += game_info->camera.playerDirectionY * movespeed;
		}
		if (game_info->map->map[(int)game_info->camera.posY][(int)(game_info->camera.posX + game_info->camera.playerDirectionX)] == '0')
		{
			game_info->camera.posX += game_info->camera.playerDirectionX * movespeed;
		}
	}
	if (keycode == KEY_S)
	{
		if (game_info->map->map[(int)(game_info->camera.posY - game_info->camera.playerDirectionY)][(int)game_info->camera.posX] == '0')
		{
			game_info->camera.posY -= game_info->camera.playerDirectionY * movespeed;
		}
		if (game_info->map->map[(int)game_info->camera.posY][(int)(game_info->camera.posX - game_info->camera.playerDirectionX)] == '0')
		{
			game_info->camera.posX -= game_info->camera.playerDirectionX * movespeed;
		}
	}
	if (keycode == KEY_D)
	{
		//double OldplayerDirectionX = game_info->camera.playerDirectionX;
		// double OldplayerDirectionX = game_info->camera.playerDirectionX;
		// game_info->camera.playerDirectionX = game_info->camera.playerDirectionX  * 	cos(20) - game_info->camera.playerDirectionY * sin(20);
		// game_info->camera.playerDirectionY = OldplayerDirectionX * sin(20) + game_info->camera.playerDirectionY * cos(20);
		double OldplayerDirectionX = game_info->camera.playerDirectionY;
		double OldplayerDirectionY = -game_info->camera.playerDirectionX;

			if (game_info->camera.playerDirectionX >= 0 && game_info->camera.playerDirectionY >= 0 
				&& game_info->map->map[(int)(game_info->camera.posY)][(int)(game_info->camera.posX + 1)] == '0')
			{
				
				game_info->camera.posX += OldplayerDirectionX * movespeed;
				game_info->camera.posY += OldplayerDirectionY * movespeed;
			}
			else if ((game_info->camera.playerDirectionX >= 0 && game_info->camera.playerDirectionY < 0)
					&& game_info->map->map[(int)(game_info->camera.posY - 1)][(int)(game_info->camera.posX)] == '0')
			{
				game_info->camera.posX += OldplayerDirectionX * movespeed;
				game_info->camera.posY += OldplayerDirectionY * movespeed;
			}
			else if ((game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY < 0)
				&& game_info->map->map[(int)(game_info->camera.posY)][(int)(game_info->camera.posX -1)] == '0')
			{
				game_info->camera.posX += OldplayerDirectionX * movespeed;
				game_info->camera.posY += OldplayerDirectionY * movespeed;
			}
			else if ((game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY >= 0)
				&& game_info->map->map[(int)(game_info->camera.posY + 1)][(int)(game_info->camera.posX)] == '0')
			{
				game_info->camera.posX += OldplayerDirectionX * movespeed;
				game_info->camera.posY += OldplayerDirectionY * movespeed;
			}
		// if (game_info->map->map[(int)game_info->camera.posY][(int)(game_info->camera.posX + game_info->camera.playerDirectionX)] == '0')
		// {
		// 	game_info->camera.posX -= game_info->camera.playerDirectionX;
		// }
			//if (game_info->camera.pl)
			// else 
			// 	game_info->camera.posY += game_info->camera.playerDirectionX;
			// if (game_info->camera.playerDirectionY < 0)
			// 	game_info->camera.posX -= game_info->camera.playerDirectionY;
			// else
			// 	game_info->camera.posX += game_info->camera.playerDirectionY;

		
		// if (game_info->map->map[(int)(game_info->camera.posY + game_info->camera.playerDirectionY)][(int)game_info->camera.posX] == '0')
		// {
		// 	if (game_info->camera.playerDirectionX > 0 && game_info->camera.playerDirectionY > 0) //++
		// 	{
		// 		game_info->camera.posX -= game_info->camera.playerDirectionY;
		// 	}
		// 	else if (game_info->camera.playerDirectionX > 0 && game_info->camera.playerDirectionY < 0) // +-
		// 	{
		// 		game_info->camera.posY -= game_info->camera.playerDirectionX;
		// 	}
		// 	else if (game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY < 0) //--
		// 	{
		// 		game_info->camera.posX += game_info->camera.playerDirectionY;
		// 	}
		// 	else if (game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY > 0)
		// 	{
		// 		game_info->camera.posY += game_info->camera.playerDirectionX;
		// 	}
		// 	game_info->camera.posY += (-game_info->camera.playerDirectionX);
		// }


		// if (game_info->map->map[(int)game_info->camera.posY][(int)(game_info->camera.posX + game_info->camera.playerDirectionX)] == '0')
		// {
		// 	game_info->camera.posX += 0;
		// }
		// if (game_info->map->map[(int)game_info->camera.posY][(int)(game_info->camera.posX + game_info->camera.playerDirectionX)] == '0')
		// {
		// 	game_info->camera.posX += game_info->camera.playerDirectionX;
		// }
	}
	if (keycode == KEY_A)
	{
		if (game_info->camera.playerDirectionX >= 0 && game_info->camera.playerDirectionY >= 0 
				&& game_info->map->map[(int)(game_info->camera.posY)][(int)(game_info->camera.posX - 1)] == '0')
				game_info->camera.posX -= 1;
			else if ((game_info->camera.playerDirectionX >= 0 && game_info->camera.playerDirectionY < 0)
					&& game_info->map->map[(int)(game_info->camera.posY + 1)][(int)(game_info->camera.posX)] == '0')
				game_info->camera.posY += 1;
			else if ((game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY < 0)
				&& game_info->map->map[(int)(game_info->camera.posY)][(int)(game_info->camera.posX + 1)] == '0')
				game_info->camera.posX += 1;
			else if ((game_info->camera.playerDirectionX < 0 && game_info->camera.playerDirectionY >= 0)
				&& game_info->map->map[(int)(game_info->camera.posY - 1)][(int)(game_info->camera.posX)] == '0')
				game_info->camera.posY -= 1;
	}
	if (keycode == KEY_RIGHT)
	{

		double OldplayerDirectionX = game_info->camera.playerDirectionX;
		game_info->camera.playerDirectionX = game_info->camera.playerDirectionX  * 	cos(-0.1 * 0.1) - game_info->camera.playerDirectionY * sin(-0.1 * 0.1);
		game_info->camera.playerDirectionY = OldplayerDirectionX * sin(-0.1 * 0.1) + game_info->camera.playerDirectionY * cos(-0.1 * 0.1);
		double oldScreenX = game_info->camera.virtualScreenX;
		game_info->camera.virtualScreenX = game_info->camera.virtualScreenX * cos(-0.1 * 0.1) - game_info->camera.virtualScreenY * sin(-0.1 * 0.1);
		game_info->camera.virtualScreenY = oldScreenX * sin(-0.1 * 0.1) + game_info->camera.virtualScreenY * cos(-0.1 * 0.1);
	}
	if (keycode == KEY_LEFT)
	{
		//env->ray.dirx = env->ray.dirx * cos(advance * 0.1) - env->ray.diry * sin(advance * 0.1);
		double OldplayerDirectionX = game_info->camera.playerDirectionX;
		game_info->camera.playerDirectionX = game_info->camera.playerDirectionX  * 	cos(0.2 * 0.1) - game_info->camera.playerDirectionY * sin(0.2 * 0.1);
		game_info->camera.playerDirectionY = OldplayerDirectionX * sin(0.2 * 0.1) + game_info->camera.playerDirectionY * cos(0.2 * 0.1);
		double oldScreenX = game_info->camera.virtualScreenX;
		game_info->camera.virtualScreenX = 	game_info->camera.virtualScreenX * cos(0.2 * 0.1) - 	game_info->camera.virtualScreenY * sin(0.2 * 0.1);
		game_info->camera.virtualScreenY = oldScreenX * sin(0.2 * 0.1) + game_info->camera.virtualScreenY * cos(0.2 * 0.1);
		//planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	//mlx_destroy_image(game_info->mlx.ptr, game_info->mlx.frame_ptr);
	//	printf("game_info->camera.playerDirectionX: %f\ngame_info->camera.playerDirectionY: %f\n",game_info->camera.playerDirectionX, game_info->camera.playerDirectionY);
	//new_frame(game_info);
	}
	return (0);
}
// enable the movement of the character by pressing WASD
void movement_of_the_character(t_game *game_info)
{
	//(void)game_info;
	mlx_hook(game_info->mlx.win, KEYPRESS, 0, movement, game_info);
}

// enable the movement of the camera by pressing ← → ↑ ↓
void movement_of_the_camera(t_game *game_info)
{
	(void)game_info;
}
