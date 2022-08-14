/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:43:48 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 17:44:45 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int	ft_exit(void *param)
{
	t_game	*info;

	info = (t_game *)param;
	ft_clean(info);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_clean(t_game *info)
{
	free_buffer(info);
	free_texture(info);
}

void	free_buffer(t_game *info)
{
	free(info->buffer);
	info->buffer = NULL;
}

void	free_texture(t_game *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(info->texture[i]);
		info->texture[i] = NULL;
		i++;
	}
	free(info->texture);
	info->texture = NULL;
}
