/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:19:58 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 17:21:40 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../mlx/mlx.h"

void	generate_texture(t_game *info, t_tex *tex)
{
	info->texture = malloc(sizeof(int *) * 4);
	create_texture_image(tex->path_no, info, 0);
	create_texture_image(tex->path_no, info, 1);
	create_texture_image(tex->path_no, info, 2);
	create_texture_image(tex->path_no, info, 3);
}

void	create_texture_image(char *path, t_game *info, int i)
{
	t_frame	tex;

	info->texture[i] = new_texture();
	tex.ptr = file_to_image(info->mlx.ptr, &tex, path);
	tex.buff = get_addr(tex.ptr, &tex.bpp, &tex.line, &tex.argb);
	get_texture(tex.buff, info->texture[i]);
	destroy_frame(&info->mlx, &tex);
}

void	get_texture(int *src, int *dst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < TEXHEIGHT)
	{
		x = 0;
		while (x < TEXWIDTH)
		{
			dst[(y * TEXWIDTH) + x] = src[(y * TEXWIDTH) + x];
			x++;
		}
		y++;
	}
}

// & (TEXHEIGHT - 1); // murY * heightTexture / heightWall
void	calculate_texture(t_game *info, t_ray *ray, int x)
{
	int		y;
	int		color;
	double	step;

	y = 0;
	step = 1.0 * TEXHEIGHT / ray->lineHeight;
	ray->texPos = (ray->drawStart - HEIGHT / 2 + ray->lineHeight / 2) * step;
	while (y < HEIGHT)
	{
		if (y < ray->drawStart)
			color = CEILING;
		else if (y >= ray->drawStart && y < ray->drawEnd)
			color = get_wall_color(ray, step, info->texture);
		else
			color = FLOOR;
		info->buffer[y * WIDTH + x] = color;
		y++;
	}
}

int	get_wall_color(t_ray *ray, double step, int **texture)
{
	int	color;
	int	texy;

	texy = (int)ray->texPos;
	ray->texPos += step;
	color = texture[0][texy * TEXWIDTH + ray->texX];
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}
