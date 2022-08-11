/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:28:41 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/11 16:24:58 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include<stdio.h>
# include <fcntl.h>
#include "libft.h"



//lien des fichiers pour les textures
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
} t_tex;

// struct pour la map
typedef struct s_data
{
	char **map; // map en double tab
	int		h;  // change nom
	int		w;	// change nom
	double	px; // 
	double	py; //
	char	p;  // 
	int		i; // pour le parcing
	t_tex*	tex;
}	t_data;

int		openfd(char *map);
void	parsing_info(t_data *data, t_tex *tex, char *map);
void	parsing_map(t_data *data, char *map);
void	get_info_map(char *map, t_data *data);
void	chek_info(t_data *data, char *map);
void	exit_map(int type, t_data *data);
int		get_color(char *str, t_data *data);

#endif