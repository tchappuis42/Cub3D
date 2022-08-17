/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:28:41 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/17 15:31:53 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define TEXWIDTH 100
# define TEXHEIGHT 100
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_texture
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		f;
	int		c;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_tex;

typedef struct s_data
{
	char	**map;
	int		h;
	int		w;
	float	px;
	float	py;
	char	p;
	int		i;
	t_tex	*tex;
}	t_data;

int		openfd(char *map, t_data *data);
void	parsing_info(t_data *data, t_tex *tex, char *map);
void	parsing_map(t_data *data, char *map);
void	get_info_map(char *map, t_data *data);
void	chek_info(t_data *data);
void	exit_map(int type, t_data *data);
int		get_color(char *str, t_data *data);
void	parsing_texture(t_data *data);

#endif