/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:26:35 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/13 17:26:53 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "game/game.h"

// Parse the map and then start the game
int	main(int argc, char **argv)
{
	t_data	data;
	t_tex	tex;

	if (argc == 2)
	{
		parsing(&data, &tex, argv[1]);
		game_start(&data, &tex);
	}
}
