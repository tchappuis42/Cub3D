/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:26:24 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 14:56:13 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "game/game.h"

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
	tex->path_no = NULL;
	tex->path_so = NULL;
	tex->path_we = NULL;
	tex->path_ea = NULL;
	tex->c = -1;
	tex->f = -1;
}

void	init_data(t_data *data, t_tex *tex)
{
	data->h = 0;
	data->w = 0;
	data->i = 0;
	data->map = NULL;
	data->p = 0;
	data->px = 0;
	data->py = 0;
	data->tex = tex;
}

void	parsing(t_data *data, t_tex *tex, char *map)
{
	init_texture(tex);
	init_data(data, tex);
	parsing_info(data, tex, map);
	get_info_map(map, data);
	parsing_map(data, map);
	chek_info(data, map);
	parsing_texture(data);
}
