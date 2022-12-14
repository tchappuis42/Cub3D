/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:26:35 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/18 15:51:38 by tchappui         ###   ########.fr       */
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
	else
		write(2, "Error: invalid args\n", 20);
}
