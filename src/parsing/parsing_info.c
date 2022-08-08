/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:06 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/08 16:08:40 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include <string.h>

static int	ft_rgb(int r, int g, int b)
{
	int	color;

	color = 0;
	color = r;
	color = color << 8;
	color += g;
	color = color << 8;
	color += b;
	return (color);
}

static int	get_color(char *str)
{
	char	**tab;
	int		r;
	int		g;
	int		b;

	tab = ft_split(str, ',');
	if (ft_tablen(tab) > 3)
		printf("null");
	r = ft_atoi(tab[0]);
	g = ft_atoi(tab[1]);
	b = ft_atoi(tab[2]);
	return (ft_rgb(r, g, b));
}

static void	get_info(t_tex *tex, char **info, t_data *data)
{

	if (ft_tablen(info) > 2)
		exit(1);
	if (ft_strcmp(info[0], "NO") == 0)
		tex->no = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "SO")))
		tex->so = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "EA")))
		tex->ea = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "WE")))
		tex->we = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "F")))
		tex->f = get_color(info[1]);
	else if (!(ft_strcmp(info[0], "C")))
		tex->c = get_color(info[1]);
	else
		exit_map(4, data); //todo
}

int	info_f(t_tex *tex)
{
	if (tex->c == -1)
		return (1);
	if (tex->no == NULL)
		return (1);
	if (tex->so == NULL)
		return (1);
	if (tex->ea == NULL)
		return (1);
	if (tex->we == NULL)
		return (1);
	if (tex->f == -1)
		return (1);
	return (0);
}

void	parsing_info(t_data *data, t_tex *tex, char *map)
{
	char	*read;
	char	**tab_read;
	int		fd;

	fd = openfd(map);
	read = get_next_line(fd); // todo readline
	tab_read = ft_split(read, ' ');
	while (info_f(tex))
	{
		if (tab_read[0][0] != '\n')
			get_info(tex, tab_read, data);
		free (read);
		read = get_next_line(fd);
		ft_tabfree(tab_read);
		tab_read = ft_split(read, ' ');
		data->i++;
	}
	free (read);
	ft_tabfree(tab_read);
}
