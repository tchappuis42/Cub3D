#include "game/game.h"
#include "../../../mlx/mlx.h"
#include <stdio.h>

int get_color_pixel(void)
{
	return (0x0000FFFF);
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

void modifying_frame(t_frame *frame)
{
	int x;
	int y;
	//int pixel;

	y = 0;
	x = 0;
	//pixel = (y * frame->line) + (4 * x);
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			//modifying_pixel((int *)&(frame->buff[pixel]), 0xe76f51, frame->argb);
			modifying_pixel2(frame, x, y, get_color_pixel());
			x++;
		}
		y++;
	}
}

void new_frame(t_mlx *mlx)
{
	printf("ko\n");
	t_frame new_frame;
	new_frame.width = 1080;
	new_frame.height = 720;
	new_frame.buff = NULL;
	new_frame.ptr = mlx_new_image(mlx->ptr, new_frame.width, new_frame.height);
	new_frame.buff = mlx_get_data_addr(new_frame.ptr, &new_frame.bpp, &new_frame.line, &new_frame.argb);
	modifying_frame(&new_frame);
	//new_frame.buff[new_frame.height * new_frame.width] = '\0'
	//printf("%s\n", new_frame.buff);
	mlx_put_image_to_window(mlx->ptr, mlx->win, new_frame.ptr, 0, 0);
}