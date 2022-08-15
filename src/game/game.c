/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:24 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/15 15:57:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/screen.h"
#include "../../mlx/mlx.h"

// get all necessary information and then launch the main loop
void	game_start(t_data *map, t_tex *tex)
{
	t_game	info;

	init_info(&info, map, tex);
	main_loop(&info);
}

// attach the struct map to info, init the graphic lib,
// create a new window and init the player viewpoint/camera
void	init_info(t_game *info, t_data *map, t_tex *tex)
{
	info->map = map;
	info->buffer = init_buffer();
	info->mlx.ptr = mlx_init();
	info->mlx.win = mlx_new_window(info->mlx.ptr, WIDTH, HEIGHT, "Cub3d");
	init_camera(&info->camera, map->px, map->py, map->p);
	generate_texture(info, tex);
}

// Start the events of the game and create new frames
void	main_loop(t_game *info)
{
	game_event(info);
	mlx_loop_hook(info->mlx.ptr, generate_screen, info);
	mlx_loop(info->mlx.ptr);
}

// launch the events of the game, movements of the player, 
// and closure of the window
void	game_event(t_game *info)
{
	mlx_key_hook(info->mlx.win, keypress_event, info);
	mlx_hook(info->mlx.win, DESTROYNOTIFY, 0, ft_exit, info);
}
