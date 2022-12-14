/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:37:19 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:38:13 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "game/game.h"
# include <math.h>

void	exit_window(t_game *info);
int		is_movement(int keycode);
void	player_rotation(int keycode, t_camera *camera);
void	rotation(t_camera *camera, double angle);
void	player_movement(int keycode, t_game *info);
void	up_movement(t_camera *camera, char **map);
void	down_movement(t_camera *camera, char **map);
void	right_movement(t_camera *camera, char **map);
void	left_movement(t_camera *camera, char **map);

#endif
