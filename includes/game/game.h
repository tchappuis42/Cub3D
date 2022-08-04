#ifndef GAME_H
#define GAME_H

#include "game/struct.h"

// init the graphic lib
void graphic_lib_init(t_mlx *mlx);

// routine of the game
void game_loop(t_mlx *mlx);

// start the event of the game
void game_event(t_mlx *mlx);




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
void keyboard_event_management(t_mlx *mlx);
// enable the movement of the character
void movement_of_the_character(t_mlx *mlx);
// enable the movement of the camera
void movement_of_the_camera(t_mlx *mlx);

// handle the other event needed by the game
void custom_event_management(t_mlx *mlx);





#endif