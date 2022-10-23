#include "board.h"

void generate_Apple(Snake* snake, Apple* a) {
    short x,y;

    srand(time(0));
    do
    {
        x = rand() % (WIDTH - 2);
        y = rand() % (HEIGHT - 1);
    } while (x == snake->pos_x && y == snake->pos_y);

    a->pos_x = x;
    a->pos_y = y;
}

void eat_Apple(Snake* snake, Apple* a) {
    points += 1;

    generate_Apple(snake, a);
}