/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:16:11 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 14:55:59 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../mlx/mlx.h"

void	draw_rectangle(t_frame *mini, int *pos, int color, t_data *map)
{
	int	i;
	int	j;
	int	pixel;
	int	h;
	int	w;

	h = ((HEIGHT / 5) / map->h);
	w = ((WIDTH / 5) / map->w);
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			pixel = ((pos[0] * h + i + 5) * mini->width)
				+ ((pos[1] * w + j + 5));
			mini->buff[pixel] = color;
			j++;
		}
		i++;
	}
}

void	draw_player(t_frame *mini, int *pos, int color, t_data *map)
{
	int	i;
	int	j;
	int	pixel;
	int	h;
	int	w;

	i = 0;
	h = ((HEIGHT / 5) / map->h);
	w = ((WIDTH / 5) / map->w);
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			pixel = ((pos[2] * h + i + 5) * mini->width)
				+ ((pos[3] * w + j + 5));
			mini->buff[pixel] = color;
			j++;
		}
		i++;
	}
}

void	draw_cadre(t_frame *minimap)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	while (x < minimap->width)
	{
		y = 0;
		while (y < minimap->height)
		{
			pixel = y * minimap->width + x;
			minimap->buff[pixel] = YELLOW;
			y++;
		}
		x++;
	}
}

void	minimap(t_mlx *mlx, t_data *map, t_camera *cam)
{
	t_frame	minimap;
	int		pos[4];

	pos[0] = 0;
	pos[2] = cam->posY;
	pos[3] = cam->posX;
	init_frame(&minimap, mlx, WIDTH / 5 + 10, HEIGHT / 5 + 10);
	draw_cadre(&minimap);
	while (pos[0] < map->h)
	{
		pos[1] = 0;
		while (pos[1] < map->w)
		{
			if (map->map[pos[0]][pos[1]] == '1')
				draw_rectangle(&minimap, pos, 0x4E4E4E, map);
			if (map->map[pos[0]][pos[1]] == '0')
				draw_rectangle(&minimap, pos, 0xF0DDC5, map);
			if (map->map[pos[0]][pos[1]] == ' ')
				draw_rectangle(&minimap, pos, 0x848483, map);
			pos[1]++;
		}
		pos[0]++;
	}
	draw_player(&minimap, pos, 0XFF0000, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, minimap.ptr, 0, 0);
}
