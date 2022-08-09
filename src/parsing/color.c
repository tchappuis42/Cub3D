/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:35:17 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/09 15:58:14 by tchappui         ###   ########.fr       */
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

int	get_color(char *str, t_data *data)
{
	char	**tab;
	int		r;
	int		g;
	int		b;

	tab = ft_split(str, ',');
	if (ft_tablen(tab) > 3)
		exit_map(5, data);
	r = ft_atoi(tab[0]);
	if (r > 255 || r < 0)
		exit_map(5, data);
	g = ft_atoi(tab[1]);
	if (g > 255 || g < 0)
		exit_map(5, data);
	b = ft_atoi(tab[2]);
	if (b > 255 || b < 0)
		exit_map(5, data);
	return (ft_rgb(r, g, b));
}
