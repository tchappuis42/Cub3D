/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:57:07 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/05 10:29:45 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "../../includes/cub3d.h"

void	get_info_map(char *map, t_data *data)
{
	char	*read;
	int		fd;
	int		i;

	i = data->i - 1;
	fd = openfd(map);
	read = get_next_line(fd);
	data->w = ft_strlen(read);
	while (i-- >= 0 || read[0] == '\n')
	{
		free(read);
		read = get_next_line(fd);
	}
	while (read != NULL)
	{
		if ((int)ft_strlen(read) > data->w)
			data->w = ft_strlen(read);
		data->h++;
		free(read);
		read = get_next_line(fd);
	}
	close (fd);
}

static void	makemap(char *tompon, t_data *data, int y)
{
	int	x;

	x = 0;
	while (tompon[x] != '\0' && tompon[x] != '\n')
	{
		data->map[y][x] = tompon[x];
		x++;
	}
	while (x < data->w)
	{
		data->map[y][x] = ' ';
		x++;
	}
	data->map[y][x] = 0;
}

void	parsing_map(t_data *data, char *map)
{
	int		y;
	char	*read;
	int		fd;

	fd = open(map, O_RDONLY);
	y = 0;
	data->map = calloc(data->h + 1, sizeof (char *));
	// malloc chek
	read = get_next_line(fd);
	while (data->i-- > 0 || read[0] == '\n')
	{
		free(read);
		read = get_next_line(fd);
	}
	while (read != NULL)
	{
		data->map[y] = calloc(data->w + 1, sizeof (char));
		//chek malloc
		makemap(read, data, y);
		y++;
		free(read);
		read = get_next_line(fd);
	}
}
