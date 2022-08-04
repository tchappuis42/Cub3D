/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parSing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:28:41 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/04 19:32:38 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"
# include <fcntl.h>

int		openfd(char *map);
void	parcing_info(t_data *data, t_tex *tex, char *map);
void	parsing_map(t_data *data, char *map);
void	get_info_map(char *map, t_data *data);
void	chek_info(t_data *data, t_tex *tex);
void	exit_map(int type, t_data *data);

#endif