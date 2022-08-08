/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:06 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/05 11:10:48 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

static void	get_info(t_tex *tex, char **info)
{
	if (ft_tablen(info) > 2)
		exit(1);
	if (!(ft_strcmp(info[0], "NO")))
		tex->no = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "SO")))
		tex->so = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "EA")))
		tex->ea = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "WE")))
		tex->we = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "F")))
		tex->f = ft_strdup(info[1]);
	else if (!(ft_strcmp(info[0], "C")))
		tex->c = ft_strdup(info[1]);
	else
		exit (0);
}

int	info_f(t_tex *tex)
{
	if (tex->c == NULL)
		return (1);
	if (tex->no == NULL)
		return (1);
	if (tex->so == NULL)
		return (1);
	if (tex->ea == NULL)
		return (1);
	if (tex->we == NULL)
		return (1);
	if (tex->f == NULL)
		return (1);
	return (0);
}

void	parcing_info(t_data *data, t_tex *tex, char *map)
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
			get_info(tex, tab_read);
		free (read);
		read = get_next_line(fd);
		if (read == NULL)
			exit(1); // message d'erreur
		ft_tabfree(tab_read);
		tab_read = ft_split(read, ' ');
		data->i++;
	}
	free (read);
}
