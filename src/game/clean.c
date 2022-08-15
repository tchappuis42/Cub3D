/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:43:48 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/15 16:39:43 by tchappui         ###   ########.fr       */
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
	free_parsing(info->map);
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

void	free_parsing(t_data *data)
{
	if (data->map != NULL)
		ft_tabfree(data->map);
	if (data->tex->path_so != NULL)
		free(data->tex->path_so);
	if (data->tex->path_no != NULL)
		free(data->tex->path_no);
	if (data->tex->path_we != NULL)
		free(data->tex->path_we);
	if (data->tex->path_ea != NULL)
		free(data->tex->path_ea);
}
