#ifndef RAYCASTING_H
#define RAYCASTING_H
#include "game/struct.h"
#include "parsing/parsing.h"
#include "game/camera.h"
enum
{
	NORTH = 0,
	WEST = 1,
	SUD = 2,
	EAST = 3
};

// The ray is composed of:
//	- a lenght
//	- a distance until the next tile
typedef struct s_ray
{

	int		mapX;		//mapX
	int		mapY;		//mapY

	double	lenghtX;		//sideDistX
	double	lenghtY;		//sideDistY

	double	nextTileX;	//deltaDistX	
	double	nextTileY;	//deltaDistX	

	double		directionX;	//rayDirX
	double		directionY;	//rayDirY

	double	towardX;		//stepX
	double	towardY; 	//stepY

	int		hit;			//hit

	double	perpWallDist;		//perpWallDist
	int		side; 			//side

}t_ray;

void calculate_drawing(t_draw *line_to_draw, t_ray *ray, double height);
void performDDA(t_ray *ray, t_data* map);
void initialize_ray3(t_ray *ray, double width, double x, double y, t_camera *camera);
void initialize_ray2(t_ray *ray, double width, double x, double y, t_camera *camera);
void initialize_ray(t_ray *ray, double width, double x, double y, t_camera *camera);

#endif