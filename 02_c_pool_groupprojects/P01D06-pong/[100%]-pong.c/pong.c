#include <stdio.h>

int update_seed(int next) { return next * 1103515245 + 12345; }

int rand(int next) {  // -1 or 1
    return ((unsigned int)(next / 65536) % 2) * 2 - 1;
}

int get_digits_count(int a) {
    int count = 1;
    while (a /= 10) count++;
    return count;
}

char input() {
    char c;

    do {
        c = getchar();
        while (getchar() != '\n')
            ;
    } while (!(c == 'A' || c == 'Z' || c == 'K' || c == 'M' || c == ' '));

    return c;
}

int player_logic(int player_y) {
    if (player_y < 0)
        player_y = 0;
    else if (player_y > 22)
        player_y = 22;
    return player_y;
}

int get_ball_dx(int ball_x, int ball_y, int ball_dx, int ball_dy, int player1_y, int player2_y) {
    if (ball_x + ball_dx == 3 && ball_y + ball_dy >= player1_y && ball_y + ball_dy <= player1_y + 2) {
        ball_dx = 1;
    } else if (ball_x + ball_dx == 77 && ball_y + ball_dy >= player2_y && ball_y + ball_dy <= player2_y + 2) {
        ball_dx = -1;
    }
    return ball_dx;
}

int get_ball_dy(int ball_y, int ball_dy) {
    if (ball_y + ball_dy <= 0) {
        ball_dy = 1;
    } else if (ball_y + ball_dy >= 24) {
        ball_dy = -1;
    }
    return ball_dy;
}

void clear_screen() { printf("\e[1;1H\e[2J"); }

void draw(int ball_x, int ball_y, int player1_y, int player2_y, int player1_score, int player2_score) {
    int i, j;

    clear_screen();
    for (j = 0; j < 25; ++j) {
        for (i = 0; i < 80; ++i)
            if (i == ball_x && j == ball_y)
                printf("o");
            else if ((i == 3 && j >= player1_y && j <= player1_y + 2) ||
                     (i == 77 && j >= player2_y && j <= player2_y + 2) ||
                     ((j % 4 == 0 || j % 4 == 3) && i == 40))
                printf("|");
            else if (i == 30 && j == 5) {
                printf("%d", player1_score);
                i += get_digits_count(player1_score) - 1;
            } else if (i == 50 && j == 5) {
                printf("%d", player2_score);
                i += get_digits_count(player2_score) - 1;
            } else
                printf(" ");
        printf("\n");
    }
}

int main() {
    static unsigned long int seed = 1;
    int player1_y, player1_score = 0, player2_y, player2_score = 0, ball_x, ball_y, ball_dx, ball_dy, b = 0;
    player1_y = 12;
    player2_y = 12;
    ball_x = 40;
    ball_y = 13;
    ball_dx = rand(seed);
    seed = update_seed(seed);
    ball_dy = rand(seed);
    seed = update_seed(seed);
    clear_screen();
    draw(ball_x, ball_y, player1_y, player2_y, player1_score, player2_score);
    while (player1_score < 21 && player2_score < 21) {
        char c = input();
        player1_y += c == 'A' ? -1 : (c == 'Z' ? 1 : 0);
        player2_y += c == 'K' ? -1 : (c == 'M' ? 1 : 0);
        player1_y = player_logic(player1_y);
        player2_y = player_logic(player2_y);
        if (ball_x <= 0) {
            player2_score++;
            b = 1;
        } else if (ball_x >= 79) {
            player1_score++;
            b = 1;
        }
        if (b) {
            b = 0;
            player1_y = 12;
            player2_y = 12;
            ball_x = 40;
            ball_y = 13;
            ball_dx = rand(seed);
            seed = update_seed(seed);
            ball_dy = rand(seed);
            seed = update_seed(seed);
        }
        ball_dx = get_ball_dx(ball_x, ball_y, ball_dx, ball_dy, player1_y, player2_y);
        ball_dy = get_ball_dy(ball_y, ball_dy);
        ball_x += ball_dx;
        ball_y += ball_dy;
        draw(ball_x, ball_y, player1_y, player2_y, player1_score, player2_score);
    }
    clear_screen();
    printf("Player %c wins! Congratulations!\n", player1_score == 21 ? '1' : '2');
    return 0;
}
