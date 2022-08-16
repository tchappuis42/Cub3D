/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:26:57 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:29:10 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "game/game.h"
# include <math.h>

typedef struct s_ray
{
	int		mapX;
	int		mapY;
	double	lengthX;
	double	lengthY;
	double	nextTileX;
	double	nextTileY;	
	double	directionX;
	double	directionY;
	double	towardX;
	double	towardY;
	int		hit;
	double	perpWallDist;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
}	t_ray;

int		*init_buffer(void);
void	calculate_wall(t_ray *ray, t_game *info, int x);
void	init_ray(t_ray *ray, t_game *info, double x);
void	length_ray(t_ray *ray, t_game *info);
void	find_wall(t_ray *ray, t_data *map);
void	get_wall_info(t_ray *ray, t_game *info);
void	calculate_texture(t_game *info, t_ray *ray, int x);
int		get_wall_color(t_ray *ray, double step, int **texture);

#endif
