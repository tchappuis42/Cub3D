/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:57:07 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 17:04:51 by tchappui         ###   ########.fr       */
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
	while (i-- >= 0 || read[0] == '\n')
	{
		free(read);
		read = get_next_line(fd);
	}
	while (read != NULL)
	{
		if ((int)ft_strlen(read) > data->w)
			data->w = ft_strlen(read) - 1;
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

int	init_map_parsing(char *map, t_data *data)
{
	int	fd;

	fd = openfd(map);
	data->map = calloc(data->h + 1, sizeof (char *));
	if (!data->map)
		exit_map(7, data);
	return (fd);
}

void	parsing_map(t_data *data, char *map)
{
	int		y;
	char	*read;
	int		fd;

	y = 0;
	fd = init_map_parsing(map, data);
	read = get_next_line(fd);
	while (data->i-- > 0 || read[0] == '\n')
	{
		free(read);
		read = get_next_line(fd);
	}
	while (read != NULL)
	{
		if (read[0] == '\n')
			exit_map(6, data);
		data->map[y] = calloc(data->w + 1, sizeof (char));
		if (!data->map[y])
			exit_map(7, data);
		makemap(read, data, y++);
		free(read);
		read = get_next_line(fd);
	}
	free(read);
	close(fd);
}
