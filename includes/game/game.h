#ifndef GAME_H
#define GAME_H

#include "game/struct.h"
#include "game/camera.h"
#include "parsing/parsing.h"

typedef struct s_game
{
	t_mlx		mlx;
	t_data		*map;
	t_camera	camera;
	
}t_game;

// init the graphic lib
void init_graphic_lib(t_game *game_info);

void init_game_info(t_game *game_info, t_data *map);

//init the wall sprit
void	init_sprit(t_game *game, t_tex *tex);

// routine of the game
void game_loop(t_game *game_info);

// start the event of the game
void game_event(t_game *game_info);
int new_frame(void *param);
void init_new_frame(t_frame *new_frame, t_mlx *mlx);
void creating_frame(t_frame *frame, t_game *game_info);
void visualisator(t_mlx *mlx, t_data *data);

void printMap(t_game *game_info);

//  ––––––––––––––––––––
// |       EVENT        |
//  ––––––––––––––––––––
// manage the window's events
void window_event_management(t_mlx *mlx);
// resize the window
void resize_window(t_mlx *mlx);
// exit the window
void exit_window(t_mlx *mlx);

// manage the events triggered by the keyboard
void keyboard_event_management(t_game *game_info);
// enable the movement of the character
void movement_of_the_character(t_game *game_info);
// enable the movement of the camera
void movement_of_the_camera(t_game *game_info);

// handle the other event needed by the game
void custom_event_management(t_game *game_info);

t_camera *init_camera(t_camera *camera, double x, double y);

void raycasting(t_camera *camera, t_data *map, t_frame *fram, double x, double y, t_draw *line_to_draw);



#endif