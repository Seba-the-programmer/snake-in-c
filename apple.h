#include "snake.h"

#ifndef apple_h
#define apple_h

typedef struct {
    short pos_x, pos_y;
} Apple;

void eat_Apple(Snake*, Apple*);
void generate_Apple(Snake*, Apple*);

int points;

#endif