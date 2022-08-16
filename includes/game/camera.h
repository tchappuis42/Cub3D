/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:00:17 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:42:36 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

// The camera represent the player's point of view
typedef struct s_camera
{
	double	posX;
	double	posY;
	double	playerDirectionx;
	double	playerDirectionY;
	double	screenX;
	double	screenY;
	double	X;
}t_camera;

void	init_camera(t_camera *camera, double x, double y, char view);
void	vector_player_position(t_camera *camera, double x, double y);
void	vector_player_direction(t_camera *camera, double dirx, double diry);
void	vector_camera_screen(t_camera *camera, double valx, double valy);

#endif
