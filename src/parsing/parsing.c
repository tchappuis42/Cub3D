/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:26:24 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/08 17:25:18 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "game/game.h"

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
	if (data->map != NULL)
		ft_tabfree(data->map);
	exit(1);
}

int	openfd(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 1)
		exit (0);
	return (fd);
}

void	init_texture(t_tex *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->we = NULL;
	tex->ea = NULL;
	tex->c = -1;
	tex->f = -1;
}

void	init_data(t_data *data)
{
	data->h = 0;
	data->w = 0;
	data->i = 0;
	data->map = NULL;
	data->p = 0;
	data->px = 0;
	data->py = 0;
}

void	parsing(t_data *data, t_tex *tex, char *map)
{
	init_texture(tex);
	init_data(data);
	parsing_info(data, tex, map);
	get_info_map(map, data);
	parsing_map(data, map);
	chek_info(data, map);
}
