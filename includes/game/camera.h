#ifndef CAMERA_H
#define CAMERA_H

// The camera represent the player's point of view
typedef struct s_camera
{
	double	posX;			  //posX
	double	posY;			  //posY
	double	playerDirectionX; //dirX
	double	playerDirectionY; //dirY
	double	screenX;   //planeX
	double	screenY;	  //planeY
	double	X;				  //cameraX

}t_camera;

void	init_camera(t_camera *camera, double x, double y, char view);
void vector_player_position(t_camera *camera, double x, double y);
void	vector_player_direction(t_camera *camera, double dirx, double diry);
void	vector_camera_screen(t_camera *camera,double valx, double valy);


#endif