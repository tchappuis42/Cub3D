/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:10:15 by tchappui          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/10 16:26:41 by tweimer          ###   ########.fr       */
=======
/*   Updated: 2022/08/11 14:54:45 by tchappui         ###   ########.fr       */
>>>>>>> 6698269e2e752d48150c801914c697a54b2529da
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"

static void	borders_x(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] != '1' && data->map[y][x] != ' ')
			exit_map(1, data);
		x++;
	}
}

static void	borders_y(t_data *data, int y, int w)
{
	if (data->map[y][0] != '1' && data->map[y][0] != ' ')
		exit_map(1, data);
	if (data->map[y][w] != '1' && data->map[y][w] != ' ')
		exit_map(1, data);
}

static void	forbiden_char(t_data *data, int y, int w)
{
	int	i;

	i = 0;
	while (++i < w)
	{
		if (data->map[y][i] != '1' && data->map[y][i] != '0'
			&& data->map[y][i] != ' ')
		{
			if (data->map[y][i] == 'N' || data->map[y][i] == 'S'
				|| data->map[y][i] == 'E' || data->map[y][i] == 'W')
			{
				data->map[y][i] = '0';
				if (data->p != 0)
					exit_map(4, data);
				data->px = i;
				data->py = y;
				data->p = data->map[y][i];
			}
			else
				exit_map(3, data);
		}
	}
}

static void	map_border(t_data *data, int y, int w)
{
	int	i;

	i = 1;
	while (i < w)
	{
		if (data->map[y][i] == ' ')
		{
			if (data->map[y - 1][i] != '1' && data->map[y - 1][i] != ' ')
				exit_map(1, data);
			if (data->map[y + 1][i] != '1' && data->map[y + 1][i] != ' ')
				exit_map(1, data);
			if (data->map[y][i + 1] != '1' && data->map[y][i + 1] != ' ')
				exit_map(1, data);
			if (data->map[y][i - 1] != '1' && data->map[y][i - 1] != ' ')
				exit_map(1, data);
		}
		i++;
	}
}

void	chek_info(t_data *data, char *map)
{
	int	y;

	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 5) != 0)
		exit_map(4, data);
	y = 0;
	while (data->map[y])
	{
		if (y == 0 || y == data->h - 1)
			borders_x(data, y);
		else
		{
			borders_y(data, y, data->w - 1);
			forbiden_char(data, y, data->w - 1);
			map_border(data, y, data->w - 1);
		}
		y++;
	}
	if (data->p == 0)
		exit_map(4, data);
}
