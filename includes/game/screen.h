/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:24:12 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:24:14 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "game/raycasting.h"

int		generate_screen(void *param);
void	display_screen(t_game *info);
void	calculate_screen(t_game *info);
void	create_frame(t_frame *frame, t_game *info);
void	init_frame(t_frame *frame, t_mlx *mlx, int width, int height);
int		*get_addr(void *ptr, int *bpp, int *line, int *argb);
void	copy_buffer_to_frame(t_frame *frame, int *buffer);
void	display_frame(t_mlx *mlx, t_frame *frame, int x, int y);
void	destroy_frame(t_mlx *mlx, t_frame *frame);
void	*file_to_image(t_mlx *mlx, t_frame *tex, char *path);

#endif
