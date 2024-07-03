#include <stdio.h>

int main(void) {

    int x, y ,z;
    int cnt;
    int lastchar;
    cnt = scanf("%d %d %d", &x, &y, &z);
    lastchar = getchar();
    if (cnt != 3 || lastchar != 0x0a) {
        printf("n/a");
        return 0;
    }
    if (x && (z || y))
        printf("1");
    else printf("0");
}