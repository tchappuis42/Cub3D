
#include "game/event.h"
#include "../../../mlx/mlx.h"

// execute the movement corresponding to the key
void player_movement(int keycode, t_game *info)
{
	char 		**map;
	t_camera	*camera;

	map = info->map->map;
	camera = &info->camera;
	if (keycode == KEY_W)
		up_movement(info, info->map->map);
	if (keycode == KEY_S)
		down_movement(info, info->map->map);
	if (keycode == KEY_D)
		right_movement(camera, map);
	if (keycode == KEY_A)
		right_movement(camera, map);
}

// UP MOVEMENT -- key W
// Move if there's no wall int the front of the player
void up_movement(t_game *info, char **map)
{
	t_camera *camera;
	//char **map;
	double playerDirectionX;
	double directionY;

	camera = &info->camera;
	//map = info->map->map;
	playerDirectionX = camera->playerDirectionX;
	directionY = camera->playerDirectionY;

	
	if (map[(int)(camera->posY + directionY)][(int)camera->posX] == '0')
			camera->posY += directionY;// * movespeed;
	if (map[(int)camera->posY][(int)(camera->posX + playerDirectionX)] == '0')
		camera->posX += playerDirectionX;// * movespeed;
}

// DOWN MOVEMENT -- key S
// Move back if there's no wall behind the player
void down_movement(t_game *info, char **map)
{
	t_camera *camera;
	//char **map;
	double playerDirectionX;
	double directionY;

	camera = &info->camera;
	//map = info->map->map;
	playerDirectionX = camera->playerDirectionX;
	directionY = camera->playerDirectionY;

	
	if (map[(int)(camera->posY - directionY)][(int)camera->posX] == '0')
			camera->posY -= directionY;// * movespeed;
	if (map[(int)camera->posY][(int)(camera->posX - playerDirectionX)] == '0')
		camera->posX -= playerDirectionX;// * movespeed;
}

// RIGHT MOVEMENT -- key D
// Rotate the playerDirection's vector by 90 degrees and move
// the player as if he were moving forward
void right_movement(t_camera *camera, char** map)
{
	double playerDirectionX = camera->playerDirectionY;
	double directionY = -camera->playerDirectionX;

	if (map[(int)(camera->posY + directionY)][(int)camera->posX] == '0')
			camera->posY += directionY; //* movespeed;
	if (map[(int)camera->posY][(int)(camera->posX + playerDirectionX)] == '0')
			camera->posX += directionY; //* movespeed;
}

// LEFT MOVEMENT -- key A
// Rotate the playerDirection's vector by -90 degrees and move
// the player as if he were moving forward
void left_movement(t_camera *camera, char** map)
{
	double playerDirectionX = -camera->playerDirectionY;
	double directionY = camera->playerDirectionX;

	if (map[(int)(camera->posY + directionY)][(int)camera->posX] == '0')
			camera->posY += directionY; //* movespeed;
	if (map[(int)camera->posY][(int)(camera->posX + playerDirectionX)] == '0')
			camera->posX += directionY; //* movespeed;
}
