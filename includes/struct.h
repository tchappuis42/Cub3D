
#ifndef STRUCT_H
#define STRUCT_H
typedef struct s_mlx
{
	void *mlx_ptr;
	void *mlx_win;
}t_mlx;



typedef struct s_frame
{
	void	*ptr;		// pointer to manipulate the image
	char	*buff;		// tab of the image's pixels
	int		bpp;		// bits per pixel
	int		line;		// number of bits in a line
	int		argb;		// argb or bgra
	int		color;		// color of the image
	int		width;		// width of the image
	int		height;		// height of the image
}	frame;

#endif