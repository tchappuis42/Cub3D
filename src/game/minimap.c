/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:16:11 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/12 15:20:19 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "../../mlx/mlx.h"

typedef struct s_mini
{
	char	*buff;
	int		bpp;
	int		line_len;
	int		endian;
}	s_mini;

void	draw_rectangle(t_mini *mini, int y, int x, int color, t_data *map)
{
	int i = 0;
	int j;
	int pixel;

	int	h = ((HEIGHT / 5) / map->h);
	int w = ((WIDTH / 5) / map->w);

	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			pixel = ((y * h + i) * mini->line_len) + ((x * w + j) * 4);
			map->buff[pixel + 0] = (color) & 0xFF;
        	map->buff[pixel + 1] = (color >> 8) & 0xFF;
        	map->buff[pixel + 2] = (color >> 16) & 0xFF;
        	map->buff[pixel + 3] = (color >> 24);
			j++;
		}
		i++;
	}
	
}

void	draw_mini(t_mini *mini, int y, int x, t_data *map)
{
	if (map->map[y][x] == 1)
		draw_rectangle(mini, y, x, 0xABCDEF, map);
	if (map->map[y][x] == 0)
		draw_rectangle(mini, y, x, 0xFFFFFF, map);
}

void	minimap(t_mlx *mlx, t_data *map)
{
	void	*minimap;
	s_mini	mini;
	int		y;
	int		x;

	y = 0;
	minimap = mlx_new_image(mlx->ptr, WIDTH / 5, HEIGHT / 5);
	mini.buff = mlx_get_data_addr(minimap, &mini.bpp, &mini.line_len, &mini.endian);
	while (y < map->h)
	{
		x = 0;
		while(x < map->w)
		{
			draw_mini(&mini, y, x, map);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, minimap, 10, 10);
}