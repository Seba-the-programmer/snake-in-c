#include "snake.h"

void init_Snake(Snake* snake, short x, short y) {
    snake->pos_x = x/2;
    snake->pos_y = y/2;
    snake->length = 0;
    snake->tail_ptr = &snake->tail;
    snake->direction.X = 1;
    snake->direction.Y = 0;
}

void move_Head(Snake* snake) {
    snake->pos_x += snake->direction.X;
    snake->pos_y += snake->direction.Y;
}
void move_Node(Node* n) {

}
int check_Borders(short x, short y) {
    if((player.pos_x + player.direction.X) == x-1 || (player.pos_x + player.direction.X) == 0) {
        return 1;
    }
    if((player.pos_y + player.direction.Y) == y-1 || (player.pos_y + player.direction.Y) == 0) {
        return 1;
    }
    return 0;
}