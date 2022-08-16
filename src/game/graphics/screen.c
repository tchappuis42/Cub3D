/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:05:04 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 17:01:27 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../../mlx/mlx.h"

int	generate_screen(void *param)
{
	t_game	*info;

	info = (t_game *)param;
	calculate_screen(info);
	display_screen(info);
	return (0);
}

void	calculate_screen(t_game *info)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		calculate_wall(&ray, info, x);
		calculate_texture(info, &ray, x);
		x++;
	}
}

void	display_screen(t_game *info)
{
	t_frame	new_frame;

	info->mlx.frame = &new_frame;
	create_frame(&new_frame, info);
	destroy_frame(&info->mlx, &new_frame);
}
