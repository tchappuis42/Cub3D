/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:26:24 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/17 15:31:23 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "game/game.h"

int	openfd(char *map, t_data *data)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_map(9, data);
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
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 5) != 0)
		exit_map(9, data);
	parsing_info(data, tex, map);
	get_info_map(map, data);
	parsing_map(data, map);
	chek_info(data);
	parsing_texture(data);
}
