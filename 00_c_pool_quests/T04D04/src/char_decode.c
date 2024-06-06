#include <stdio.h>

void charDecode();
void charCode();

int main(int argc, char *argv[]) {
    if (argc < 1) return printf("%d", argc);

    switch (*argv[1]) {
        case '0':
            charCode();
            break;
        case '1':
            charDecode();
            break;
        default:
            printf("n/a");
            break;
    }

    return 0;
}

void charDecode() {
    char empty;
    int params;
    while (1) {
        scanf("%X%c", &params, &empty);
        if (params > 255 || params < 16) {
            printf("n/a");
            return;
        }
        if (empty == '\n') {
            printf("%c", params);
            return;
        }
        if (empty != ' ') {
            printf("n/a");
            return;
        }
        printf("%c ", params);
    }
}

void charCode() {
    char empty;
    char params;
    while (1) {
        scanf("%c%c", &params, &empty);
        if (empty == '\n') {
            printf("%X", params);
            return;
        }
        if (empty != ' ') {
            printf("n/a");
            return;
        }
        printf("%X ", params);
    }
}