/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:22:17 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/15 17:02:57 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "../../mlx/mlx.h"

int	*new_texture(void)
{
	int		i;
	int		*texture;

	i = 0;
	texture = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	while (i < TEXHEIGHT * TEXHEIGHT)
	{
		texture[i] = 0;
		i++;
	}
	return (texture);
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

void	copy_buffer_to_frame(t_frame *frame, int *buffer)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		frame->buff[i] = buffer[i];
		buffer[i] = 0;
		i++;
	}
}

void	*file_to_image(t_mlx *mlx, t_frame *tex, char *path)
{
	return (mlx_xpm_file_to_image(mlx->ptr, path, &tex->width, &tex->height));
}
