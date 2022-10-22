#ifndef snake_h
#define snake_h

typedef struct{
    short pos_x, pos_y;
} Node;
typedef struct{
    short X, Y;
} Vec2;
typedef struct{
    short pos_x, pos_y, length;
    Node tail;
    Node* tail_ptr;
    Vec2 direction;
} Snake;

void init_Snake(Snake* snake, short x, short y);
void move_Head(Snake* snake);
void move_Node(Node* n);
int check_Borders(short x, short y);

Snake player;

#endif