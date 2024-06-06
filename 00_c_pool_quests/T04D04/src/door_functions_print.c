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

void printFunc(double charge()) {
    char matrixFunc[21][42];

    for (int i = 0; i < 21; i++) {
        for (int g = 0; g < 42; g++) {
            matrixFunc[i][g] = ' ';
            if (g == 21) matrixFunc[i][g] = '|';
        }
    }

    // todo
    for (int i = 0; i < 42; i++) {
        matrixFunc[1][i] = '_';
    }

    double maxNumb = -1;

    for (int i = 0; i < 42; i++) {
        double ptemp = -PI + (2 * PI / 41) * i;
        double u = charge(ptemp);
        if (u > maxNumb && u < 5) maxNumb = u;
    }

    double inter = maxNumb / 21;
    for (int i = 0; i < 42; i++) {
        double ptemp = -PI + (2 * PI / 41) * i;
        double u = charge(ptemp);
        for (int j = 20; j > 0; j--) {
            if (u >= j * inter && u < (j + 1) * inter) matrixFunc[j][i] = '*';
        }
    }
    for (int i = 20; i > 0; i--) {
        for (int j = 0; j < 42; j++) printf("%c", matrixFunc[i][j]);
        printf("\n");
    }
}

int main() {
    printFunc(Aniesi);
    printf("\n\n");
    printFunc(Bernulli);
    printf("\n\n");
    printFunc(Hyperbola);

    return 1;
}