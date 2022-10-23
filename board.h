#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include <windows.h>

#ifndef board_h
#define board_h
#define WIDTH 60
#define HEIGHT 20

void create_Game();
void update_Game();
void render_Game();
void get_Input();
void end_Game();

char area[20][61];
char input;

#endif