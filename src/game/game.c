#include "game/game.h"
#include "../../mlx/mlx.h"

typedef struct s_mini
{
	char	*buff;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mini;

void	draw_rectangle(t_mini *mini, int y, int x, int color, t_data *map)
{
	int i = 0;
	int j;
	int pixel;

	int	h = ((HEIGHT / 5) / map->h);
	int w = ((WIDTH / 5) / map->w);

	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			pixel = ((y * h + i + 5) * mini->line_len) + ((x * w + j + 5) * 4);
			mini->buff[pixel + 0] = (color) & 0xFF;
        	mini->buff[pixel + 1] = (color >> 8) & 0xFF;
        	mini->buff[pixel + 2] = (color >> 16) & 0xFF;
        	mini->buff[pixel + 3] = (color >> 24);
			j++;
		}
		i++;
	}
	
}
void	draw_player(t_mini *mini, int y, int x, int color, t_data *map)
{
	int i = 0;
	int j;
	int pixel;

	(void)map;
	int	h = ((HEIGHT / 5) / map->h);
	int w = ((WIDTH / 5) / map->w);

	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			pixel = ((y * h + i + 5) * mini->line_len) + ((x * w + j + 5) * 4);
			mini->buff[pixel + 0] = (color) & 0xFF;
        	mini->buff[pixel + 1] = (color >> 8) & 0xFF;
        	mini->buff[pixel + 2] = (color >> 16) & 0xFF;
        	mini->buff[pixel + 3] = (color >> 24);
			j++;
		}
		i++;
	}
	
}

void	draw_cadre(t_mini *mini)
{
	int	i = 0;
	int	j;
	int pixel;
	int color = 0XF2FF00;

	while (i < 210)
	{
		j = 0;
		while(j < 210)
		{
			pixel = (i * mini->line_len) + (j * 4);
			mini->buff[pixel + 0] = (color) & 0xFF;
        	mini->buff[pixel + 1] = (color >> 8) & 0xFF;
        	mini->buff[pixel + 2] = (color >> 16) & 0xFF;
        	mini->buff[pixel + 3] = (color >> 24);
			j++;
		}
		i++;
	}
}

void	minimap(t_mlx *mlx, t_data *map, t_camera *cam)
{
	void	*minimap;
	t_mini	mini;
	int		y;
	int		x;

	y = 0;
	minimap = mlx_new_image(mlx->ptr, WIDTH / 5 + 10, HEIGHT / 5 + 10);
	mini.buff = mlx_get_data_addr(minimap, &mini.bpp, &mini.line_len, &mini.endian);
	draw_cadre(&mini);
	while (y < map->h)
	{
		x = 0;
		while(x < map->w)
		{
			if (map->map[y][x] == '1')
				draw_rectangle(&mini, y, x, 0x4E4E4E, map);
			if (map->map[y][x] == '0')
				draw_rectangle(&mini, y, x, 0xF0DDC5, map);
			if (map->map[y][x] == ' ')
				draw_rectangle(&mini, y, x, 0x848483, map);
			x++;
		}
		y++;
	}
	draw_player(&mini, cam->posY, cam->posX, 0XFF0000, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, minimap, 0, 0);
}

// get all necessary information and then launch the main loop
void	game_start(t_data *map, t_tex *tex)
{
	t_game	info;

	init_info(&info, map, tex);
	main_loop(&info);
}

// attach the struct map to info, init the graphic lib,
// create a new window and init the player viewpoint/camera
void init_info(t_game *info, t_data *map, t_tex *tex)
{
	info->map = map;
	info->mlx.ptr = mlx_init();
	info->mlx.win = mlx_new_window(info->mlx.ptr, WIDTH, HEIGHT, "Cub3d");
	init_camera(&info->camera, map->px, map->py);
	generate_texture(info, tex);
}

// Start the events of the game and create new frames
void	main_loop(t_game *info)
{
	game_event(info);
	mlx_loop_hook(info->mlx.ptr, generate_screen, info);
	mlx_loop(info->mlx.ptr);
}

// launch the events of the game, movements of the player, and closure of the window
void	game_event(t_game *info)
{
	mlx_key_hook(info->mlx.win, keypress_event, info);
	mlx_hook(info->mlx.win, DESTROYNOTIFY, 0, ft_exit, info);
}
