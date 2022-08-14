/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:16:11 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/13 17:45:44 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../mlx/mlx.h"

void	draw_rectangle(t_frame *mini, int y, int x, int color, t_data *map)
{
	int i; 
	int j;
	int pixel;

	int	h = ((HEIGHT / 5) / map->h);
	int w = ((WIDTH / 5) / map->w);
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			pixel = ((y * h + i + 5) * mini->width) + ((x * w + j + 5));
			mini->buff[pixel] = color;
			j++;
		}
		i++;
	}
	
}
void	draw_player(t_frame *mini, int y, int x, int color, t_data *map)
{
	int i = 0;
	int j;
	int pixel;

	(void)map;
	int	h = ((HEIGHT / 5) / map->h);
	int w = ((WIDTH / 5) / map->w);

	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			pixel = ((y * h + i + 5) * mini->width) + ((x * w + j + 5));
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
	int pixel;

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
	t_frame minimap;
	int		y;
	int		x;

	y = 0;
	init_frame(&minimap, mlx, WIDTH / 5 + 10, HEIGHT / 5 + 10);
	draw_cadre(&minimap);
	while (y < map->h)
	{
		x = 0;
		while(x < map->w)
		{
			if (map->map[y][x] == '1')
				draw_rectangle(&minimap, y, x, 0x4E4E4E, map);
			if (map->map[y][x] == '0')
				draw_rectangle(&minimap, y, x, 0xF0DDC5, map);
			if (map->map[y][x] == ' ')
				draw_rectangle(&minimap, y, x, 0x848483, map);
			x++;
		}
		y++;
	}
	draw_player(&minimap, cam->posY, cam->posX, 0XFF0000, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, minimap.ptr, 0, 0);
}

// typedef struct s_mini
// {
// 	char	*buff;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }	s_mini;

// void	draw_rectangle(t_mini *mini, int y, int x, int color, t_data *map)
// {
// 	int i = 0;
// 	int j;
// 	int pixel;

// 	int	h = ((HEIGHT / 5) / map->h);
// 	int w = ((WIDTH / 5) / map->w);

// 	while (i < h)
// 	{
// 		j = 0;
// 		while (j < w)
// 		{
// 			pixel = ((y * h + i) * mini->line_len) + ((x * w + j) * 4);
// 			map->buff[pixel + 0] = (color) & 0xFF;
//         	map->buff[pixel + 1] = (color >> 8) & 0xFF;
//         	map->buff[pixel + 2] = (color >> 16) & 0xFF;
//         	map->buff[pixel + 3] = (color >> 24);
// 			j++;
// 		}
// 		i++;
// 	}
	
// }

// void	draw_mini(t_mini *mini, int y, int x, t_data *map)
// {
// 	if (map->map[y][x] == 1)
// 		draw_rectangle(mini, y, x, 0xABCDEF, map);
// 	if (map->map[y][x] == 0)
// 		draw_rectangle(mini, y, x, 0xFFFFFF, map);
// }

// void	minimap(t_mlx *mlx, t_data *map)
// {
// 	void	*minimap;
// 	s_mini	mini;
// 	int		y;
// 	int		x;

// 	y = 0;
// 	minimap = mlx_new_image(mlx->ptr, WIDTH / 5, HEIGHT / 5);
// 	mini.buff = mlx_get_data_addr(minimap, &mini.bpp, &mini.line_len, &mini.endian);
// 	while (y < map->h)
// 	{
// 		x = 0;
// 		while(x < map->w)
// 		{
// 			draw_mini(&mini, y, x, map);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(mlx->ptr, mlx->win, minimap, 10, 10);
// }