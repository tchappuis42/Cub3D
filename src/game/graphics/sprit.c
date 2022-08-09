/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:38:43 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/09 18:15:28 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include "game/game.h"
#include "../../../mlx/mlx.h"

static void	wall_no(t_tex *tex, t_game *game)
{
	int			img_width;
	int			img_height;

	tex->no = mlx_xpm_file_to_image(game->mlx.ptr, tex->path_no, &img_width, &img_height);
}

static void	wall_so(t_tex *tex, t_game *game)
{
	int			img_width;
	int			img_height;

	tex->so = mlx_xpm_file_to_image(game->mlx.ptr, tex->path_so, &img_width, &img_height);
}

static void	wall_ea(t_tex *tex, t_game *game)
{
	int			img_width;
	int			img_height;

	tex->ea = mlx_xpm_file_to_image(game->mlx.ptr, tex->path_ea, &img_width, &img_height);
}

static void	wall_we(t_tex *tex, t_game *game)
{
	int			img_width;
	int			img_height;

	tex->we = mlx_xpm_file_to_image(game->mlx.ptr, tex->path_we, &img_width, &img_height);
}

void	init_sprit(t_game *game, t_tex *tex)
{
	wall_no(tex, game);
	wall_so(tex, game);
	wall_ea(tex, game);
	wall_we(tex, game);
}
