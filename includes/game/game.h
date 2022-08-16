/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:38:50 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:40:42 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "game/struct.h"
# include "game/camera.h"
# include "parsing/parsing.h"

# define YELLOW 0XF2FF00
# define NORTH 0
# define SOUTH 1
# define WEST 3
# define EAST 2

typedef struct s_game
{
	t_mlx		mlx;
	t_data		*map;
	t_camera	camera;
	int			*buffer;
	int			**texture;
}t_game;

void	game_start(t_data *map, t_tex *tex);
void	init_info(t_game *info, t_data *map, t_tex *tex);
void	main_loop(t_game *info);
void	game_event(t_game *info);
int		keypress_event(int keycode, void *param);
int		generate_screen(void *param);
int		ft_exit(void *param);
void	generate_texture(t_game *info, t_tex *tex);
void	create_texture_image(char *path, t_game *info, int i);
int		ft_exit(void *param);
void	ft_clean(t_game *info);
void	minimap(t_mlx *mlx, t_data *map, t_camera *cam);
int		*new_texture(void);
void	get_texture(int *src, int *dst);
void	free_buffer(t_game *info);
void	free_texture(t_game *info);
void	free_parsing(t_data *data);

#endif
