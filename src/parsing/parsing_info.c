/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:06 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/09 15:59:15 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

static void	get_info(t_tex *tex, char **info, t_data *data)
{
	if (ft_tablen(info) > 2)
	{
		if (info[2][0] != '\n')
			exit_map(6, data);
	}
	if (!(ft_strcmp(info[0], "NO")))
		tex->no = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "SO")))
		tex->so = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "EA")))
		tex->ea = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "WE")))
		tex->we = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "F")))
		tex->f = get_color(info[1], data);
	else if (!(ft_strcmp(info[0], "C")))
		tex->c = get_color(info[1], data);
	else
		exit_map(6, data);
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

void	remove_enter(t_tex *tex)
{
	tex->no[ft_strlen(tex->no) - 1] = 0;
	tex->so[ft_strlen(tex->so) - 1] = 0;
	tex->ea[ft_strlen(tex->ea) - 1] = 0;
	tex->we[ft_strlen(tex->we) - 1] = 0;
}

void	parsing_info(t_data *data, t_tex *tex, char *map)
{
	char	*read;
	char	**tab_read;
	int		fd;

	fd = openfd(map);
	read = get_next_line(fd);
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
	remove_enter(tex);
}
