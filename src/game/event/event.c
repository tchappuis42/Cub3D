/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:31:03 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:07:57 by tchappui         ###   ########.fr       */
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
		player_rotation(keycode, &info->camera);
	if (keycode == is_movement(keycode))
		player_movement(keycode, info);
	return (0);
}

// Destroy the actual frame, clear the screen and then destroy it,
// before calling the final function before exiting the program
void	exit_window(t_game *info)
{
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
void	player_rotation(int keycode, t_camera *camera)
{
	if (keycode == KEY_RIGHT)
		rotation(camera, 0.2);
	else if (keycode == KEY_LEFT)
		rotation(camera, -0.2);
}

// Rotate the virtualScreen and the player's direction
// See the rotation matrix to understand the modification of the two vector
void	rotation(t_camera *camera, double angle)
{
	double		vectorx;
	double		vectory;

	vectorx = camera->directionx;
	vectory = camera->directiony;
	camera->directionx = vectorx * cos(angle) - vectory * sin(angle);
	camera->directiony = vectorx * sin(angle) + vectory * cos(angle);
	vectorx = camera->screenx;
	vectory = camera->screeny;
	camera->screenx = vectorx * cos(angle) - vectory * sin(angle);
	camera->screeny = vectorx * sin(angle) + vectory * cos(angle);
}
