#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include <conio.h>
#include <windows.h>

#ifndef board_h
#define board_h

void create_Game();
void update_Game();
void render_Game();
void get_Input();
void end_Game();
void process_Input();

char area[20][61];
char input;

#endif