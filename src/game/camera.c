/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:34:59 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 15:35:16 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/camera.h"

// We create a camera that will represent the player's pointof view.
// To do so, we need:
//	- The position of le player(x, y)
//	- The direction of the player's mouvement
//	- A virtual screen that
void	init_camera(t_camera *camera, double x, double y)
{
	vector_player_position(camera, x, y);
	vector_player_direction(camera);
	vector_camera_screen(camera);
}

// The player start at his start position
void	vector_player_position(t_camera *camera, double x, double y)
{
	camera->posX = x;
	camera->posY = y;
}

// The direction of the player is represented as a vector
// with a component x and y
void	vector_player_direction(t_camera *camera)
{
	camera->playerDirectionX = -1;
	camera->playerDirectionY = 0;
}

// The screen of the camera is also a vector, that must be
// perpendicular to the direction of the player.
void	vector_camera_screen(t_camera *camera)
{
	camera->screenX = 0;
	camera->screenY = 0.66;
}
