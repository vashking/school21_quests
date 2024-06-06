#include <math.h>
#include <stdio.h>

#define PI 3.141593

double exetional(double x) { return pow(x, 2); }

double Bernulli(double x) {
    if (sqrt(1 + 4 * exetional(x)) - exetional(x) - 1 < 0) return 1;
    double y = sqrt(sqrt(1 + 4 * exetional(x)) - exetional(x) - 1);
    return y;
}
// todo
double Hyperbola(double x) {
    double y = 1 / (exetional(x));
    return y;
}

double Aniesi(double x) {
    double y = 1 / (1 + exetional(x));
    return y;
}

int main() {
    for (int i = 0; i < 42; i++) {
        double ptemp = -PI + (2 * PI / 41) * i;
        printf("%.7f | %.7f | ", ptemp, Aniesi(ptemp));

        if (Bernulli(ptemp) == 1) {
            printf("-- | ");
        } else {
            printf("%.7f | ", Bernulli(ptemp));
        }
        printf("%.7f\n", Hyperbola(ptemp));
    }
    return 0;
}