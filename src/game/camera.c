/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:34:59 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:05:23 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/camera.h"
#include <stdio.h>
// We create a camera that will represent the player's pointof view.
// To do so, we need:
//	- The position of le player(x, y)
//	- The direction of the player's mouvement
//	- A virtual screen that
void	init_camera(t_camera *camera, double x, double y, char view)
{
	vector_player_position(camera, x, y);
	if (view == 'S')
	{
		vector_player_direction(camera, 0, 1);
		vector_camera_screen(camera, -0.66, 0);
	}
	else if (view == 'W')
	{
		vector_player_direction(camera, -1, 0);
		vector_camera_screen(camera, 0, -0.66);
	}
	else if (view == 'E')
	{
		vector_player_direction(camera, 1, 0);
		vector_camera_screen(camera, 0, 0.66);
	}
	else
	{
		vector_player_direction(camera, 0, -1);
		vector_camera_screen(camera, 0.66, 0);
	}
}

// The player start at his start position
void	vector_player_position(t_camera *camera, double x, double y)
{
	camera->posx = x;
	camera->posy = y;
}

// The direction of the player is represented as a vector
// with a component x and y
void	vector_player_direction(t_camera *camera, double dirx, double diry)
{
	camera->directionx = dirx;
	camera->directiony = diry;
}

// The screen of the camera is also a vector, that must be
// perpendicular to the direction of the player.
void	vector_camera_screen(t_camera *camera, double valx, double valy)
{
	camera->screenx = valx;
	camera->screeny = valy;
}
