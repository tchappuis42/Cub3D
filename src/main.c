#include "../mlx/mlx.h"
#include "../includes/struct.h"

int main()
{
	t_mlx mlx;
	frame one;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 1080, 720, "test");
	one.ptr = mlx_new_image(mlx.mlx_ptr, 1080, 720);
	one.buff = mlx_get_data_addr(one.ptr, &one.bpp, &one.line, &one.argb);
	int i = 0;
	while (one.buff[i] != '\0')
	{
		
		i++;
	}
	mlx_loop(mlx.mlx_ptr);
}