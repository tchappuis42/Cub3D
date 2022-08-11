/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:37:14 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/11 16:04:08 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/raycasting.h"
#include "../../../mlx/mlx.h"

void	calculate_screen(t_game *info)
{
	int		x;
	t_ray	ray;

	x = 0;
	info->buffer = init_buffer();
	while (x < WIDTH)
	{
		calculate_wall(&ray, info, x);
		calculate_texture(info, &ray, x);
		x++;
	}
}

int	*init_buffer(void)
{
	int		i;
	int		*buffer;

	i = 0;
	buffer = malloc(sizeof(int *) * HEIGHT * WIDTH);
	while (i < HEIGHT * WIDTH)
	{
		
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

void	calculate_wall(t_ray *ray, t_game *info, int x)
{
	init_ray(ray, info, x);
	length_ray(ray, info);
	performDDA(ray, info->map);
	get_wall_info(ray, info);
}

void	init_ray(t_ray *ray, t_game *info, double x)
{
	t_camera	*camera;

	camera = &info->camera;
	camera->X = 2 * x / WIDTH - 1;
	ray->directionX = camera->playerDirectionX + camera->screenX * camera->X;
	ray->directionY = camera->playerDirectionY + camera->screenY * camera->X;
	ray->nextTileX = fabs(1 / ray->directionX);
	ray->nextTileY = fabs(1 / ray->directionY);
	ray->mapX = (int)camera->posX;
	ray->mapY = (int)camera->posY;
	if (ray->directionX == 0)
		ray->nextTileX = 1e30;
	else
		ray->nextTileX = fabs(1 / ray->directionX);
	if (ray->directionY == 0)
		ray->nextTileY = 1e30;
	else
		ray->nextTileY = fabs(1 / ray->directionY);
	ray->hit = 0;
}

void	length_ray(t_ray *ray, t_game *info)
{
	t_camera	*camera;

	camera = &info->camera;
	if (ray->directionX < 0)
	{
		ray->towardX = -1;
		ray->lengthX = (camera->posX - ray->mapX) * ray->nextTileX;
	}
	else
	{
		ray->towardX = -1;
		ray->lengthX = (ray->mapX + 1.0 - camera->posX) * ray->nextTileX;
	}
	if (ray->directionY < 0)
	{
		ray->towardY = -1;
		ray->lengthY = (camera->posY - ray->mapY) * ray->nextTileY;
	}
	else
	{
		ray->towardY = 1;
		ray->lengthY = (ray->mapY + 1.0 - camera->posY) * ray->nextTileY;
	}
}

void	performDDA(t_ray *ray, t_data* map)
{
    while (ray->hit == 0 )
    {
    	if (ray->lengthX < ray->lengthY)
		{
			ray->lengthX += ray->nextTileX;
			ray->mapX += ray->towardX;
			ray->side = 0;
        }
        else
        {
			ray->lengthY += ray->nextTileY;
        	ray->mapY += ray->towardY;
          	ray->side = 1;
        }
        if (map->map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
    }
	if (ray->side == 0)
		ray->perpWallDist = (ray->lengthX - ray->nextTileX);
    else
		ray->perpWallDist = (ray->lengthY - ray->nextTileY);
}


void	get_wall_info(t_ray *ray, t_game *info)
{
	t_camera	*camera;

	camera = &info->camera;
	ray->lineHeight = (int)(HEIGHT / ray->perpWallDist);
	ray->drawStart = (-ray->lineHeight) / 2 + HEIGHT / 2;
	ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	if (ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT - 1;
    if (ray->side == 0)
	  	ray->wallX = camera->posY + ray->perpWallDist * ray->directionY;
    else
		ray->wallX = camera->posX + ray->perpWallDist * ray->directionX;
    ray->wallX -= floor(ray->wallX);
	ray->texX = (int)(ray->wallX * (double)TEXWIDTH);
    if (ray->side == 0 && ray->directionX > 0)
		ray->texX = TEXWIDTH - ray->texX - 1;
    if (ray->side == 1 && ray->directionY < 0)
		ray->texX = TEXWIDTH - ray->texX - 1;
}

void calculate_texture(t_game *info, t_ray *ray, int x)
{
	int texY;
	int color;
	int y;

	y = 0;
	double step = 1.0 * TEXHEIGHT / ray->lineHeight;
	ray->texPos = (ray->drawStart - HEIGHT / 2 + ray->lineHeight / 2) * step;
	while (y < HEIGHT)
	{
		if (y < ray->drawStart)
		{
			color = 0x00ff00;
		}
		else if (y >= ray->drawStart &&  y < ray->drawEnd)
		{
			texY = (int)ray->texPos;// & (TEXHEIGHT - 1); // murY * heightTexture / heightWall
			ray->texPos += step;
			color = info->texture[0][texY * TEXWIDTH + ray->texX];
			if (ray->side == 1)
				color = (color >> 1) & 8355711;
		}
		else
		{
			color = 0x00ffff;
		}
		info->buffer[y * WIDTH + x] = color;
		y++;
	}
}
