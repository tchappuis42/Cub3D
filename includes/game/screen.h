#ifndef SCREEN_H
#define SCREEN_H

#include "game/game.h"
int generate_screen(void *param);
void display_screen(t_game *info);
void init_new_frame(t_frame *new_frame, t_mlx *mlx);
void creating_frame(t_frame *frame, t_game *info);
void calculate_screen(t_game *info);
#endif