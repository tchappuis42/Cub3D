/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:18:51 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/17 16:46:46 by tchappui         ###   ########.fr       */
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
		write(2, "Error : map border\n", 19);
	if (type == 2)
		write(2, "Error : no player\n", 18);
	if (type == 3)
		write(2, "Error : forbiden char\n", 22);
	if (type == 4)
		write(2, "Error : too many player\n", 24);
	if (type == 5)
		write(2, "Error : format color\n", 21);
	if (type == 6)
		write(2, "Error : map invalid\n", 20);
	if (type == 7)
		write(2, "Error : malloc error\n", 21);
	if (type == 8)
		write(2, "Error : texture file\n", 21);
	if (type == 9)
		write(2, "Error : format file\n", 20);
	if (data->map != NULL)
		ft_tabfree(data->map);
	free_tex(data->tex);
	exit(1);
}
