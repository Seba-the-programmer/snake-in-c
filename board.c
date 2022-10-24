#include "board.h"

void create_Game() {
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            if(x==0 || y==0 || x==(WIDTH-1) || y==(HEIGHT-1))
                area[y][x] = '#';
            else area[y][x] = ' ';
        }
        area[y][WIDTH] = '\n';
    }

    points = 0;
    generate_Apple(&player, &apple);
    init_Snake(&player, WIDTH, HEIGHT);
}

void update_Game() {
    if(check_Borders(WIDTH, HEIGHT)) end_Game();
    if(player.pos_x == apple.pos_x && player.pos_y == apple.pos_y) {
        eat_Apple(&player, &apple);
    }

    move_Tail(&player);
    move_Head(&player);
}

void render_Game() {
    get_Input();
    update_Game();

    system("@cls||clear");
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x <= WIDTH; x++) {
            //render head
            if(y == player.pos_y && x == player.pos_x) {
                printf("@");
                continue;
            }
            //render tail
            byte flag = 0;
            for(size_t n=0;n<player.length;n++) {
                if(y == player.tail[n].pos_y && x == player.tail[n].pos_x) {
                    printf("@");
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            //render apple
            if(y == apple.pos_y && x == apple.pos_x) {
                printf("*");
                continue;
            }
            printf("%c", area[y][x]);
        }
    }
    printf("Points: %d\n", points);

    Sleep(300);

}

void end_Game() {

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