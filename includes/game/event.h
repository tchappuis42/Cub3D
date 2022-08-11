#ifndef EVENT_H
#define EVENT_H
#include "game/game.h"
#include <math.h>

void exit_window(t_game *info);
int is_movement(int keycode);
void player_rotation(int keycode, t_game *info);
void rotation(t_game *info, double angle);

void player_movement(int keycode, t_game *info);
void up_movement(t_game *info, char **map);
void down_movement(t_game *info, char **map);
void right_movement(t_camera *camera, char** map);
void left_movement(t_camera *camera, char** map);

#endif