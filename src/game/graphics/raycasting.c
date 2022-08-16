/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:14:22 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:02:16 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/raycasting.h"
#include "../../../mlx/mlx.h"

void	calculate_wall(t_ray *ray, t_game *info, int x)
{
	init_ray(ray, info, x);
	length_ray(ray, info);
	find_wall(ray, info->map);
	get_wall_info(ray, info);
}

void	init_ray(t_ray *ray, t_game *info, double x)
{
	t_camera	*camera;

	camera = &info->camera;
	camera->x = 2 * x / WIDTH - 1;
	ray->directionx = camera->directionx + camera->screenx * camera->x;
	ray->directiony = camera->directiony + camera->screeny * camera->x;
	ray->tilex = fabs(1 / ray->directionx);
	ray->tiley = fabs(1 / ray->directiony);
	ray->mapx = (int)camera->posx;
	ray->mapy = (int)camera->posy;
	if (ray->directionx == 0)
		ray->tilex = 1e30;
	else
		ray->tilex = fabs(1 / ray->directionx);
	if (ray->directiony == 0)
		ray->tiley = 1e30;
	else
		ray->tiley = fabs(1 / ray->directiony);
	ray->hit = 0;
}

void	length_ray(t_ray *ray, t_game *info)
{
	t_camera	*camera;

	camera = &info->camera;
	if (ray->directionx < 0)
	{
		ray->towardx = -1;
		ray->lengthx = (camera->posx - ray->mapx) * ray->tilex;
	}
	else
	{
		ray->towardx = 1;
		ray->lengthx = (ray->mapx + 1.0 - camera->posx) * ray->tilex;
	}
	if (ray->directiony < 0)
	{
		ray->towardy = -1;
		ray->lengthy = (camera->posy - ray->mapy) * ray->tiley;
	}
	else
	{
		ray->towardy = 1;
		ray->lengthy = (ray->mapy + 1.0 - camera->posy) * ray->tiley;
	}
}

void	find_wall(t_ray *ray, t_data *map)
{
	while (ray->hit == 0)
	{
		if (ray->lengthx < ray->lengthy)
		{
			ray->lengthx += ray->tilex;
			ray->mapx += ray->towardx;
			ray->side = 0;
		}
		else
		{
			ray->lengthy += ray->tiley;
			ray->mapy += ray->towardy;
			ray->side = 1;
		}
		if (map->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->lengthx - ray->tilex);
	else
		ray->perpwalldist = (ray->lengthy - ray->tiley);
}

void	get_wall_info(t_ray *ray, t_game *info)
{
	t_camera	*camera;

	camera = &info->camera;
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->draw_start = (-ray->lineheight) / 2 + HEIGHT / 2;
	ray->draw_end = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wallx = camera->posy + ray->perpwalldist * ray->directiony;
	else
		ray->wallx = camera->posx + ray->perpwalldist * ray->directionx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)TEXWIDTH);
	if (ray->side == 0 && ray->directionx > 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	if (ray->side == 1 && ray->directiony < 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
}
