#include "snake.h"

void init_Snake(Snake* snake, short x, short y) {
    // Node node;
    // node.pos_x = x/2;
    // node.pos_y = y/2;

    snake->pos_x = x/2;
    snake->pos_y = y/2;
    snake->length = 0;
    // snake->tail[0] = node;
    snake->direction.X = 1;
    snake->direction.Y = 0;
}

void move_Head(Snake* snake) {
    snake->pos_x += snake->direction.X;
    snake->pos_y += snake->direction.Y;
}
void move_Tail(Snake* snake) {
    if(snake->length <= 0) return;

    for(int n = (snake->length-1);n>0;n--) {
        snake->tail[n].pos_x = snake->tail[n-1].pos_x;
        snake->tail[n].pos_y = snake->tail[n-1].pos_y;
    }
    snake->tail[0].pos_x = snake->pos_x;
    snake->tail[0].pos_y = snake->pos_y;
}
void add_Node(Snake* snake) {
    Node new_Node;
    new_Node.pos_x = snake->tail[snake->length - 1].pos_x;
    new_Node.pos_y = snake->tail[snake->length - 1].pos_y;
    snake->tail[snake->length] = new_Node;
    snake->length += 1;
}
int check_Borders(Snake* snake, short x, short y) {
    if((snake->pos_x + snake->direction.X) == x-1 || (snake->pos_x + snake->direction.X) == 0) {
        return 1;
    }
    if((snake->pos_y + snake->direction.Y) == y-1 || (snake->pos_y + snake->direction.Y) == 0) {
        return 1;
    }
    return 0;
}

int check_Collisions(Snake* snake, short x, short y) {
    if(check_Borders(snake, x, y)) return 1;

    for (int n = 0; n < snake->length; n++) {
        if(snake->pos_x == snake->tail[n].pos_x && snake->pos_y == snake->tail[n].pos_y)
            return 1;
    }
    return 0;
}