/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:35:17 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 16:51:46 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"

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

void clean_color(char **tab, t_data *data, int exit)
{
	ft_tabfree(tab);
	if (exit == 1)
		exit_map(5, data);
}

int	get_color(char *str, t_data *data)
{
	char	**tab;
	int		r;
	int		g;
	int		b;

	tab = ft_split(str, ',');
	if (ft_tablen(tab) > 3)
		clean_color(tab, data, 1);
	r = ft_atoi(tab[0]);
	if (r > 255 || r < 0)
		clean_color(tab, data, 1);
	g = ft_atoi(tab[1]);
	if (g > 255 || g < 0)
		clean_color(tab, data, 1);
	b = ft_atoi(tab[2]);
	if (b > 255 || b < 0)
		clean_color(tab, data, 1);
	clean_color(tab, data, 0);
	return (ft_rgb(r, g, b));
}
