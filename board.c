#include "board.h"

void create_Game() {
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            if(x==0 || y==0 || x==(WIDTH-1) || y==(HEIGHT-1))
                area[y][x] = '#';
            else area[y][x] = '.';
        }
        area[y][WIDTH] = '\n';
    }

    init_Snake(&player, WIDTH, HEIGHT);
}

void update_Game() {
    if(check_Borders(WIDTH, HEIGHT)) end_Game();
    move_Tail(&player);
    move_Head(&player);
}

void render_Game() {
    update_Game();

    system("@cls||clear");
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x <= WIDTH; x++) {
            //render head
            if(y == player.pos_y && x == player.pos_x) {
                printf("@");
            } else {
                //render tail
                for(size_t n=0;n<player.length;n++) {
                    if(y == player.tail[0].pos_y && x == player.tail[0].pos_x) {
                        printf("@");
                    } else printf("%c", area[y][x]);
                }
            }
        }
    }
    get_Input();
    Sleep(550);
}

void end_Game() {
    //free all pointers and other shit

    exit(0);
}

void get_Input() {
    if(GetAsyncKeyState(VK_ESCAPE)) end_Game();
    else if(GetAsyncKeyState(VK_UP) && player.direction.Y != 1) {
        player.direction.X = 0;
        player.direction.Y = -1;
    } else if(GetAsyncKeyState(VK_DOWN) && player.direction.Y != -1) {
        player.direction.X = 0;
        player.direction.Y = 1;
    } else if(GetAsyncKeyState(VK_LEFT) && player.direction.X != 1) {
        player.direction.X = -1;
        player.direction.Y = 0;
    } else if(GetAsyncKeyState(VK_RIGHT) && player.direction.X != -1) {
        player.direction.X = 1;
        player.direction.Y = 0;
    }
}