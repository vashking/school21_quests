#include <stdio.h>
#include <math.h>

int main(void) {
    
    double R;
    double m;
    char c;
    scanf("%lf%c", &R, &c);
    if (R >= 0 && c == 0x0a) {
        m = 21500 * ((double) 4 / 3) * M_PI * pow(R, 3);
        double round (double m);
        printf("%.0lf", m);
    } else {
        printf("n/a");
        return 0;
    }
}
