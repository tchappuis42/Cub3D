/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:31:03 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/11 14:47:06 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/event.h"
#include "../../../mlx/mlx.h"

// If a key pressed correspond to an event, it is executed
int	keypress_event(int keycode, void *param)
{
	t_game	*info;

	info = (t_game *)param;
	if (keycode == KEY_ESCAPE)
		exit_window(info);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		player_rotation(keycode, info);
	if (keycode == is_movement(keycode))
		player_movement(keycode, info);
	return (0);
}

// Destroy the actual frame, clear the screen and then destroy it,
// before calling the final function before exiting the program
void	exit_window(t_game *info)
{
	mlx_destroy_image(info->mlx.ptr, info->mlx.frame->ptr);
	mlx_clear_window(info->mlx.ptr, info->mlx.win);
	mlx_destroy_window(info->mlx.ptr, info->mlx.win);
	ft_clean(info);
	exit(EXIT_SUCCESS);
}

// Determine if the key enter is WASD or not
int	is_movement(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A)
		return (keycode);
	if (keycode == KEY_S || keycode == KEY_D)
		return (keycode);
	return (keycode - 1);
}

// Event of the rotation of the player,rotate the VirtualScreen 
// and the direction of the player by x degree
void	player_rotation(int keycode, t_game *info)
{
	if (keycode == KEY_RIGHT)
		rotation(info, -0.5);
	else if (keycode == KEY_LEFT)
		rotation(info, 0.5);
}

// Rotate the virtualScreen and the player's direction
// See the rotation matrix to understand the modification of the two vector
void	rotation(t_game *info, double angle)
{
	double		vectorx;
	double		vectory;
	t_camera	*camera;

	camera = &info->camera;
	vectorx = camera->playerDirectionX;
	vectory = camera->playerDirectionY;
	camera->playerDirectionX = vectorx * cos(angle) - vectory * sin(angle);
	camera->playerDirectionY = vectorx * sin(angle) + vectory * cos(angle);
	vectorx = camera->screenX;
	vectory = camera->screenY;
	camera->screenX = vectorx * cos(angle) - vectory * sin(angle);
	camera->screenY = vectorx * sin(angle) + vectory * cos(angle);
}
