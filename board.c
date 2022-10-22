#include "board.h"

const short width_ = 60;
const short height_ = 20;

void create_Game() {
    for (size_t y = 0; y < height_; y++) {
        for (size_t x = 0; x < width_; x++) {
            if(x==0 || y==0 || x==(width_-1) || y==(height_-1))
                area[y][x] = '#';
            else area[y][x] = '.';
        }
        area[y][width_] = '\n';
    }

    //Snake
    init_Snake(&player, width_, height_);
}

void update_Game() {
    if(check_Borders(width_, height_)) end_Game();
    if(player.length > 0) {
        for (size_t i = 0; i < player.length; i++) {
            move_Node(player.tail_ptr);
        }
    }
    move_Head(&player);
}

void render_Game() {
    update_Game();

    system("@cls||clear");
    for (size_t y = 0; y < height_; y++) {
        for (size_t x = 0; x <= width_; x++) {
            if(y == player.pos_y && x == player.pos_x) {
                printf("@");
            } else printf("%c", area[y][x]);
        }
    }
    get_Input();
    Sleep(250);
}

void end_Game() {
    free(player.tail_ptr);

    exit(0);
}

void get_Input() {
    struct timeval tmo;
    fd_set readfds;

    fflush(stdout);

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec = 1;
    tmo.tv_usec = 0;
    select(1, &readfds, NULL, NULL, &tmo);
    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        input = getch();
        return process_Input();
    }
}
void process_Input() {
    if(input == 'q') end_Game();
    else if(input == 'w' && player.direction.Y != 1) {
        player.direction.X = 0;
        player.direction.Y = -1;
    } else if(input == 's' && player.direction.Y != -1) {
        player.direction.X = 0;
        player.direction.Y = 1;
    } else if(input == 'a' && player.direction.X != 1) {
        player.direction.X = -1;
        player.direction.Y = 0;
    } else if(input == 'd' && player.direction.X != -1) {
        player.direction.X = 1;
        player.direction.Y = 0;
    }
}