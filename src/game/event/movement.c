/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:29:12 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 14:47:40 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/event.h"
#include "../../../mlx/mlx.h"

// execute the movement corresponding to the key
void	player_movement(int keycode, t_game *info)
{
	if (keycode == KEY_W)
		up_movement(&info->camera, info->map->map);
	if (keycode == KEY_S)
		down_movement(&info->camera, info->map->map);
	if (keycode == KEY_D)
		right_movement(&info->camera, info->map->map);
	if (keycode == KEY_A)
		left_movement(&info->camera, info->map->map);
}

// UP MOVEMENT -- key W
// Move if there's no wall int the front of the player
void	up_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->playerDirectionX;
	directiony = camera->playerDirectionY;
	if (map[(int)(camera->posY + directiony)][(int)camera->posX] == '0')
			camera->posY += directiony;
	if (map[(int)camera->posY][(int)(camera->posX + directionx)] == '0')
		camera->posX += directionx;
}

// DOWN MOVEMENT -- key S
// Move back if there's no wall behind the player
void	down_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->playerDirectionX;
	directiony = camera->playerDirectionY;
	if (map[(int)(camera->posY - directiony)][(int)camera->posX] == '0')
			camera->posY -= directiony;
	if (map[(int)camera->posY][(int)(camera->posX - directionx)] == '0')
		camera->posX -= directionx;
}

// RIGHT MOVEMENT -- key D
// Rotate the playerDirection's vector by 90 degrees and move
// the player as if he were moving forward
void	right_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->screenX;
	directiony = camera->screenY;
	if (map[(int)(camera->posY + directiony)][(int)camera->posX] == '0')
			camera->posY += directiony;
	if (map[(int)camera->posY][(int)(camera->posX + directionx)] == '0')
			camera->posX += directionx;
}

// LEFT MOVEMENT -- key A
// Rotate the playerDirection's vector by -90 degrees and move
// the player as if he were moving forward
void	left_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->screenX;
	directiony = camera->screenY;
	if (map[(int)(camera->posY - directiony)][(int)camera->posX] == '0')
			camera->posY -= directiony;
	if (map[(int)camera->posY][(int)(camera->posX - directionx)] == '0')
			camera->posX -= directionx;
}
