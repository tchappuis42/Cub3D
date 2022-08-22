/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:25:21 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/22 13:39:09 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"

static void	borders_x(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] == ' ')
		{
			if (y == 0)
			{
				if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
					exit_map(1, data);
			}
			if (y == data->h - 1)
			{
				if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
					exit_map(1, data);
			}
		}
		else if (data->map[y][x] != '1')
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
	if (data->map[y][0] == ' ')
	{
		if (data->map[y][1] != '1' && data->map[y][1] != ' ')
			exit_map(1, data);
	}
	if (data->map[y][w] == ' ')
	{
		if (data->map[y][w - 1] != '1' && data->map[y][w - 1] != ' ')
			exit_map(1, data);
	}
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
				if (data->p != 0)
					exit_map(4, data);
				data->px = i + 0.5;
				data->py = y + 0.5;
				data->p = data->map[y][i];
				data->map[y][i] = '0';
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

void	chek_info(t_data *data)
{
	int	y;

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
		exit_map(2, data);
}
