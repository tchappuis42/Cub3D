#include "game/screen.h"
#include "../../../mlx/mlx.h"

int generate_screen(void *param)
{
	t_game *info;

	info = (t_game *)param;

	calculate_screen(info);
	display_screen(info);
	return (0);
}

void display_screen(t_game *info)
{
	t_frame new_frame;

	info->mlx.frame = &new_frame;
	init_new_frame(&new_frame, &info->mlx);
	creating_frame(&new_frame, info);
	mlx_destroy_image(info->mlx.ptr, new_frame.ptr);
}

void init_new_frame(t_frame *new_frame, t_mlx *mlx)
{
	new_frame->width =  WIDTH;
	new_frame->height = HEIGHT;
	new_frame->buff = NULL;
	new_frame->ptr = mlx_new_image(mlx->ptr, new_frame->width, new_frame->height);
	new_frame->buff = (int*)mlx_get_data_addr(new_frame->ptr, &new_frame->bpp, &new_frame->line, &new_frame->argb);
}

void creating_frame(t_frame *frame, t_game *info)
{
	int x;
	int y;
	int pixel;

	y = 0;
	x = 0;
	while (x < frame->width)
	{
	 	y = 0;
		while (y < frame->height )
		{
			pixel = (y * frame->width) + (x);
			frame->buff[pixel] = info->buffer[pixel];
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx.ptr, info->mlx.win, frame->ptr, 0, 0);
	for(y = 0; y < HEIGHT; y++)
		for(x = 0; x < WIDTH; x++) 
			info->buffer[ (y * frame->width) + (x)] = 0;
}
