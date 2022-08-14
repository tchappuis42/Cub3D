/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:21 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 16:46:59 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../../mlx/mlx.h"

void	create_frame(t_frame *frame, t_game *info)
{
	init_frame(frame, &info->mlx, WIDTH, HEIGHT);
	copy_buffer_to_frame(frame, info->buffer);
	display_frame(&info->mlx, frame, 0, 0);
	minimap(&info->mlx, info->map, &info->camera);
}

void	init_frame(t_frame *frame, t_mlx *mlx, int width, int height)
{
	frame->buff = NULL;
	frame->width = width;
	frame->height = height;
	frame->ptr = mlx_new_image(mlx->ptr, width, height);
	frame->buff = get_addr(frame->ptr, &frame->bpp, &frame->line, &frame->argb);
}

int	*get_addr(void *ptr, int *bpp, int *line, int *argb)
{
	return ((int *)mlx_get_data_addr(ptr, bpp, line, argb));
}

void	display_frame(t_mlx *mlx, t_frame *frame, int x, int y)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, frame->ptr, x, y);
}

void	destroy_frame(t_mlx *mlx, t_frame *frame)
{
	mlx_destroy_image(mlx->ptr, frame->ptr);
}
