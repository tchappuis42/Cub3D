#include "game/raycasting.h"
#include "game/camera.h"
#include "game/game.h"
#include "parsing/parsing.h"
#include <math.h>

void raycasting(t_camera *camera, t_data *map, t_frame *frame, double x, double y, t_draw *line_to_draw)
{
	t_ray 	ray;
	
	
	(void)y;
	initialize_ray(&ray, (double)frame->width, x, y, camera);
	initialize_ray2(&ray, (double)frame->width, x, y, camera);
	initialize_ray3(&ray, (double)frame->width, x, y, camera);
	
	performDDA(&ray, map);
	calculate_drawing(line_to_draw, &ray, frame->height);
	
	
	//ray->stepX = sqrt(1 + (ray->directionY * ray->directionY) / (ray->directionX * ray->directionX));
	//ray->stepY = sqrt(1 + ( * ray->directionX) / (ray->directionY * ray->directionY));
}

void initialize_ray(t_ray *ray, double width, double x, double y, t_camera *camera)
{
	(void)y;
	camera->X = 2 * x / width - 1;

	ray->directionX = camera->playerDirectionX + camera->virtualScreenX * camera->X;
	ray->directionY = camera->playerDirectionY + camera->virtualScreenY * camera->X;
	//ray->nextTileX = sqrt(1 + (ray->directionY * ray->directionY) / (ray->directionX * ray->directionX));
	//ray->nextTileY = sqrt(1 + (ray->directionX * ray->directionX) / (ray->directionY * ray->directionY));


	ray->nextTileX = fabs(1 / ray->directionX);
	ray->nextTileY = fabs(1 / ray->directionY);
	//printf("ray->directionX %f, ray->directionY %f \nray->nextTileY %f, ray->nextTileX %f\n", ray->directionX, ray->directionY, ray->nextTileY, ray->nextTileX);
	//printf("%f\n",camera->X);
	// static int i = 0;
	// if (i == 1081)
	// 	exit(0);
	// i++;
}

void initialize_ray2(t_ray *ray, double width, double x, double y, t_camera *camera)
{
	(void)y;
	(void)x;
	(void)width;

	ray->mapX = (int)camera->posX;
	ray->mapY = (int)camera->posY;
	//	printf("camera->posX %f mapX %d\n, camera->posY %f mapY %d\n", camera->posX,ray->mapX,   camera->posY, ray->mapY);
	if (ray->directionX == 0)
		ray->nextTileX = 1e30; //1e30
	else
		ray->nextTileX = fabs(1 / ray->directionX );
		//ray->nextTileX = sqrt(1 + (ray->directionY * ray->directionY) / (ray->directionX * ray->directionX));
		
	if (ray->directionY == 0)
		ray->nextTileY = 1e30;//1e30
	else
		ray->nextTileY = fabs(1 / ray->directionY);
		//ray->nextTileY = sqrt(1 + (ray->directionX * ray->directionX) / (ray->directionY * ray->directionY));
	
	ray->hit = 0;
}

void initialize_ray3(t_ray *ray, double width, double x, double y, t_camera *camera)
{
	(void)y;
	(void)x;
	(void)width;
	if (ray->directionX < 0)
	{
		ray->towardX = -1;	
		ray->lenghtX = (camera->posX - ray->mapX) * ray->nextTileX;
	}
	else
    { 
		ray->towardX = -1;
		ray->lenghtX = (ray->mapX + 1.0 - camera->posX) * ray->nextTileX;
    } 
   	if (ray->directionY < 0) 
    {
		ray->towardY = -1; 
		ray->lenghtY = (camera->posY - ray->mapY) * ray->nextTileY; 
    }
	else
    { 
    	ray->towardY = 1; 
        ray->lenghtY = (ray->mapY + 1.0 - camera->posY) * ray->nextTileY;
    }
}

void performDDA(t_ray *ray, t_data* map)
{
	//perform DDA
    while (ray->hit == 0 )
    {
		
        //jump to next map square, either in x-direction, or in y-direction
    	if (ray->lenghtX < ray->lenghtY)
		{
			
			ray->lenghtX += ray->nextTileX;
			ray->mapX += ray->towardX;
			ray->side = 0;
        }
        else
        {
			ray->lenghtY += ray->nextTileY;
			//"111111111111111111111111"
		//	printf("ray->mapY %d, ray->mapX %d, toardY %f, both %f\n", ray->mapY, ray->mapX, ray->towardY, ray->mapY + ray->towardY);
        	ray->mapY += ray->towardY;
          	ray->side = 1;
        }
	
        //Check if ray has hit a wall
        if (map->map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
    }
	if (ray->side == 0)
		ray->perpWallDist = (ray->lenghtX - ray->nextTileX);
    else
		ray->perpWallDist = (ray->lenghtY - ray->nextTileY);
}

void calculate_drawing(t_draw *line_to_draw, t_ray *ray, double height)
{
	
	line_to_draw->lineHeight = (int)(height / ray->perpWallDist);
	line_to_draw->drawStart = (-line_to_draw->lineHeight) / 2 + height / 2;
	line_to_draw->drawEnd = line_to_draw->lineHeight / 2 + height / 2;
	if (line_to_draw->drawStart < 0)
		line_to_draw->drawStart = 0;
	if (line_to_draw->drawEnd >= height)
		line_to_draw->drawEnd = height - 1;
	line_to_draw->side = ray->side;
	line_to_draw->mapX = ray->mapX;
	line_to_draw->mapY = ray->mapY;
}