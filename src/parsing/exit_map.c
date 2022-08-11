/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:18:51 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/11 15:19:34 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "game/game.h"

void	free_tex(t_tex *tex)
{
	if (tex->path_so != NULL)
		free(tex->path_so);
	if (tex->path_no != NULL)
		free(tex->path_no);
	if (tex->path_we != NULL)
		free(tex->path_we);
	if (tex->path_ea != NULL)
		free(tex->path_ea);
}

void	exit_map(int type, t_data *data)
{
	if (type == 1)
		printf("Error : bordures\n");
	if (type == 2)
		printf("Error : pas de player\n");
	if (type == 3)
		printf("Error : forbiden char\n");
	if (type == 4)
		printf("Error : trop de player\n");
	if (type == 5)
		printf("Error : color");
	if (type == 6)
		printf("Error : ");
	if (type == 7)
		printf("Error : Malloc error");
	if (data->map != NULL)
		ft_tabfree(data->map);
	free_tex(data->tex);
	exit(1);
}
