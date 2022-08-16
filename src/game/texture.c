/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:19:58 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:03:49 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../mlx/mlx.h"

void	generate_texture(t_game *info, t_tex *tex)
{
	int	i;

	i = 0;
	info->texture = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		info->texture[i] = NULL;
		i++;
	}
	create_texture_image(tex->path_no, info, NORTH);
	create_texture_image(tex->path_so, info, SOUTH);
	create_texture_image(tex->path_ea, info, EAST);
	create_texture_image(tex->path_we, info, WEST);
}

void	create_texture_image(char *path, t_game *info, int i)
{
	t_frame	tex;

	info->texture[i] = new_texture();
	tex.ptr = file_to_image(info->mlx.ptr, &tex, path);
	if (tex.ptr == NULL)
	{
		ft_clean(info);
		write(STDERR_FILENO, "Error: texture not found\n", 25);
		exit(EXIT_FAILURE);
	}
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
	step = 1.0 * TEXHEIGHT / ray->lineheight;
	ray->texpos = (ray->draw_start - HEIGHT / 2 + ray->lineheight / 2) * step;
	while (y < HEIGHT)
	{
		if (y < ray->draw_start)
			color = info->map->tex->c;
		else if (y >= ray->draw_start && y < ray->draw_end)
			color = get_wall_color(ray, step, info->texture);
		else
			color = info->map->tex->f;
		info->buffer[y * WIDTH + x] = color;
		y++;
	}
}

int	get_wall_color(t_ray *ray, double step, int **texture)
{
	int	color;
	int	texy;

	texy = (int)ray->texpos;
	ray->texpos += step;
	if (ray->side == 0)
	{
		if (ray->towardx > 0)
			color = texture[WEST][texy * TEXWIDTH + ray->texx];
		else
			color = texture[EAST][texy * TEXWIDTH + ray->texx];
	}
	else
	{
		if (ray->towardy > 0)
			color = texture[SOUTH][texy * TEXWIDTH + ray->texx];
		else
			color = texture[NORTH][texy * TEXWIDTH + ray->texx];
	}
	return (color);
}
