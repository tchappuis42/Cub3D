/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:28:41 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/08 16:04:08 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include<stdio.h>
# include <fcntl.h>
#include "libft.h"

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
}	t_data;

//lien des fichiers pour les textures
typedef struct s_texture 
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
} t_tex;

int		openfd(char *map);
void	parsing_info(t_data *data, t_tex *tex, char *map);
void	parsing_map(t_data *data, char *map);
void	get_info_map(char *map, t_data *data);
void	chek_info(t_data *data, char *map);
void	exit_map(int type, t_data *data);

#endif