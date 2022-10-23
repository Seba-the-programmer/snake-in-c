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
    Node tail[100];
    Vec2 direction;
} Snake;

void init_Snake(Snake*, short x, short y);
void move_Head(Snake*);
void move_Tail(Snake*);
void add_Node(Snake*);
int check_Borders(short x, short y);

Snake player;

#endif