/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:06 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/12 14:48:03 by tchappui         ###   ########.fr       */
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
		tex->path_no = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "SO")))
		tex->path_so = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "EA")))
		tex->path_ea = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "WE")))
		tex->path_we = ft_strdup(info[1]);
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
	if (tex->path_no == NULL)
		return (1);
	if (tex->path_so == NULL)
		return (1);
	if (tex->path_ea == NULL)
		return (1);
	if (tex->path_we == NULL)
		return (1);
	if (tex->f == -1)
		return (1);
	return (0);
}

void	remove_enter(t_tex *tex)
{
	tex->path_no[ft_strlen(tex->path_no) - 1] = 0;
	tex->path_so[ft_strlen(tex->path_so) - 1] = 0;
	tex->path_ea[ft_strlen(tex->path_ea) - 1] = 0;
	tex->path_we[ft_strlen(tex->path_we) - 1] = 0;
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
