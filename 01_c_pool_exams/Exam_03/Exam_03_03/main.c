#include <stdio.h>
#include <math.h>

int main(void) {
    int x;
    int tp, sp ,fp;
    int minus = 0;
    int lastchar;
    int cnt;
    cnt = scanf("%d", &x); 
    lastchar = getchar();
    if (x < 0) {
        minus = 1;
    }
    x = fabs(x);
    if (cnt != 1 || lastchar != 0x0a) {
        printf("n/a");
        return 0;
    }
    tp = x % 10;
    x = x / 10;
    sp = x % 10;
    fp = x / 10;
    if (minus == 1) {
        printf("-%d%d%d", tp, sp, fp);
    }
    else {
        printf("%d%d%d", tp, sp, fp);
    }
}