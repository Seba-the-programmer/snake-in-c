#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "snake.h"
#include "apple.h"

#ifndef board_h
#define board_h
#define WIDTH 35
#define HEIGHT 15

void create_Game();
void update_Game();
void render_Game();
void get_Input();
void end_Game();

char area[HEIGHT][WIDTH+1];
Apple apple;

#endif