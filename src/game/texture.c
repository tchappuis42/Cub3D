#include "game/game.h"
#include "../../mlx/mlx.h"
int *newtexture(void)
{
	int		y;
	int		x;
	int		*texture;

	y = 0;
	x = 0;
	texture = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	while (y < TEXHEIGHT)
	{
		x = 0;
		while(x < TEXWIDTH)
		{
			texture[y * TEXWIDTH + x] = 0;
			x++;
		}
		y++;
	}
	return (texture);
}

void generate_texture(t_game *info, t_tex *tex)
{

	printf("YOLO: %s\n", tex->path_no);
	info->texture = malloc(sizeof(int *) * 4);	
	create_texture_image(tex->path_no, info, 0);
	// texture[1] = create_texture_image(tex->so, mlx_ptr);
	// texture[2] = create_texture_image(tex->we, mlx_ptr);
	// texture[3] = create_texture_image(tex->ea, mlx_ptr);
}

void copy_texture(int *src, int *dst)
{
	int x = 0;
	int y = 0;
	while (y < TEXHEIGHT)
	{
		x = 0;
		while(x < TEXWIDTH)
		{
			dst[(y * TEXWIDTH) + x] = src[(y * TEXWIDTH) + x];
			x++;
		}
		y++;
	}
}

void create_texture_image(char *path, t_game *info, int i)
{
	t_frame new_texture;

	(void)path;
	info->texture[i] = newtexture();
	new_texture.ptr  =  mlx_xpm_file_to_image(info->mlx.ptr, "./assets/grass2.xpm", &new_texture.width, &new_texture.height);
	new_texture.buff = (int*)mlx_get_data_addr(new_texture.ptr, &new_texture.bpp, &new_texture.line, &new_texture.argb);
	copy_texture(new_texture.buff, info->texture[i]);
	mlx_destroy_image(info->mlx.ptr, new_texture.ptr);
}
