#ifndef RAYCASTING_H
#define RAYCASTING_H
#include "game/game.h"
#include <math.h>
enum
{
	NORTH = 0,
	WEST = 1,
	SUD = 2,
	EAST = 3
};


typedef struct s_ray
{

	int		mapX;		//mapX
	int		mapY;		//mapY

	double	lengthX;		//sideDistX
	double	lengthY;		//sideDistY

	double	nextTileX;	//deltaDistX	
	double	nextTileY;	//deltaDistX	

	double		directionX;	//rayDirX
	double		directionY;	//rayDirY

	double	towardX;		//stepX
	double	towardY; 	//stepY

	int		hit;			//hit

	double	perpWallDist;		//perpWallDist
	int		side; 			//side

	int lineHeight;
	int drawStart;
    int drawEnd;

	double wallX;
	int texX;
	double step;
	double texPos;

}t_ray;

void calculate_screen(t_game *info);
int *init_buffer(void);
void calculate_wall(t_ray *ray, t_game *info, int x);
void init_ray(t_ray *ray, t_game* info, double x);
void length_ray(t_ray *ray, t_game *info);
void performDDA(t_ray *ray, t_data* map);
void get_wall_info(t_ray *ray, t_game *info);
void calculate_texture(t_game *info, t_ray *ray, int x);
#endif