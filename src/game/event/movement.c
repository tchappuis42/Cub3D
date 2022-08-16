/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:29:12 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:26:43 by tchappui         ###   ########.fr       */
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

	directionx = camera->directionx * 0.1;
	directiony = camera->directiony * 0.1;
	if (map[(int)(camera->posy + directiony)][(int)camera->posx] == '0')
			camera->posy += directiony;
	if (map[(int)camera->posy][(int)(camera->posx + directionx)] == '0')
		camera->posx += directionx;
}

// DOWN MOVEMENT -- key S
// Move back if there's no wall behind the player
void	down_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->directionx * 0.1;
	directiony = camera->directiony * 0.1;
	if (map[(int)(camera->posy - directiony)][(int)camera->posx] == '0')
			camera->posy -= directiony;
	if (map[(int)camera->posy][(int)(camera->posx - directionx)] == '0')
		camera->posx -= directionx;
}

// RIGHT MOVEMENT -- key D
// Rotate the playerDirection's vector by 90 degrees and move
// the player as if he were moving forward
void	right_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->screenx * 0.1;
	directiony = camera->screeny * 0.1;
	if (map[(int)(camera->posy + directiony)][(int)camera->posx] == '0')
			camera->posy += directiony;
	if (map[(int)camera->posy][(int)(camera->posx + directionx)] == '0')
			camera->posx += directionx;
}

// LEFT MOVEMENT -- key A
// Rotate the playerDirection's vector by -90 degrees and move
// the player as if he were moving forward
void	left_movement(t_camera *camera, char **map)
{
	double	directionx;
	double	directiony;

	directionx = camera->screenx * 0.1;
	directiony = camera->screeny * 0.1;
	if (map[(int)(camera->posy - directiony)][(int)camera->posx] == '0')
			camera->posy -= directiony;
	if (map[(int)camera->posy][(int)(camera->posx - directionx)] == '0')
			camera->posx -= directionx;
}
