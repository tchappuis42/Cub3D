#include "game/game.h"
#include "../../../mlx/mlx.h"
#include <stdio.h>
#include<math.h>


void printMap(t_game *game_info)
{
	//int w = game_info->map->w;
	int h = game_info->map->h;
	int y = 0;
	int x = 0;
	char *str;
	

	while (y < h)
	{
		str = ft_strdup(game_info->map->map[y]);
		
		x = 0;
		while( str[x])
		{
			if (str[x] == 'N')
			{
				str[x] = '0';
			}
			if ((int)game_info->camera.posX == x
				&& (int)game_info->camera.posY == y)
			{
					str[x] = 'X';
			}
			x++;
		}
		//printf("%s\n", str);
		mlx_string_put(game_info->mlx.ptr, game_info->mlx.win,  20,  20 * y, 0xff101f, str);
		y++;
	}
	//printf("%s\n", str);
}



int new_frame(void *param)
{
	
	t_frame new_frame;
	t_game *game_info;

	game_info = (t_game *)param;
	init_new_frame(&new_frame, &game_info->mlx);
	creating_frame(&new_frame, game_info);
	//game_info->mlx.frame_ptr = &new_frame;
	mlx_destroy_image(game_info->mlx.ptr, new_frame.ptr);
	return (0);
}

void init_new_frame(t_frame *new_frame, t_mlx *mlx)
{
	new_frame->width = 1080;
	new_frame->height = 720;
	new_frame->buff = NULL;
	new_frame->ptr = mlx_new_image(mlx->ptr, new_frame->width, new_frame->height);
	new_frame->buff = mlx_get_data_addr(new_frame->ptr, &new_frame->bpp, &new_frame->line, &new_frame->argb);
}



int get_color_pixel(char **map, int mapX, int mapY, int side)
{
	int color;

	if (map[mapY][mapX] == ' ')
	{
		color = 0xcc527a;
	}
	else if (map[mapY][mapX] == '1')
	{
		color = 0xc20114;
	}
	else if (map[mapY][mapX] == '0')
	{
		color = 0xffd966;
	}

	if (side == 1)
		color = color / 2;
	return (color);

}

void modifying_pixel2(t_frame *frame, int x, int y, int color)
{
	int	pixel;

	pixel = (y * frame->line) + (x * 4);
	if (frame->argb == 1)
	{
		frame->buff[pixel + 0] = ((color) >> 24) & 0xFF;
		frame->buff[pixel + 1] = ((color) >> 16) & 0xFF;
		frame->buff[pixel + 2] = ((color) >> 8) & 0xFF;
		frame->buff[pixel + 3] = (color) & 0xFF;
	}
	else if (frame->argb == 0)
	{
		frame->buff[pixel + 0] = (color) & 0xFF;
		frame->buff[pixel + 1] = ((color) >> 8) & 0xFF;
		frame->buff[pixel + 2] = ((color) >> 16) & 0xFF;
		frame->buff[pixel + 3] = ((color) >> 24) & 0xFF;
	}
}

void modifying_pixel(int *pixel, int color, int argb)
{
	if (argb == 1)
	{
		*pixel  = color;
		
	}
	else if (argb == 0)
	{
		*pixel  = color;
	}
}

void creating_frame(t_frame *frame, t_game *game_info)
{
	int x;
	int y;
	t_draw	line_to_draw;

	//int pixel;

	y = 0;
	x = 0;
	//int posX = frame->width / 2;
	//int posY = frame->height / 2;

	//pixel = (y * frame->line) + (4 * x);
	//printf("SEG\n");
	while (x < frame->width)
	{
		
	 	y = 0;
		
		while (y < frame->height )
		{

			//printf("SEG\n");
			raycasting(&game_info->camera, game_info->map, frame, x, y, &line_to_draw);
			//printf("SEG2\n");
			if (y >= line_to_draw.drawStart && y <= line_to_draw.drawEnd)
			{
				modifying_pixel2(frame, x, y, get_color_pixel(game_info->map->map, line_to_draw.mapX, line_to_draw.mapY, line_to_draw.side));
			}
			else if (y < line_to_draw.drawStart)
			{
				modifying_pixel2(frame, x, y, 0xb8f3ff);
			}
			else
			{
				modifying_pixel2(frame, x, y, 0x757e8e);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game_info->mlx.ptr, game_info->mlx.win, frame->ptr, 0, 0);

	//printMap(game_info);
	//printf("SEG2\n");
}


