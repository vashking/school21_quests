#include <stdio.h>
#define NMAX 10
int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
    return 0;
}

int input(int *a, int *n) {
    if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > NMAX))
        return 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1)
            return 1;
    }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        return 1;
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1)
            printf(" ");
    }
}

int max(int *a, int n) {
    int max = 0;
    for (int* p = a; p - a < n; p++) {
        if (*p > max)
            max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int min = 1000000000;
    for (int* p = a; p - a < n; p++) {
        if (*p < min)
            min = *p;
    }
    return min;
}

double mean(int *a, int n) {
    double mean = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++)
        mean += (double)*p * probability;
    return mean;
}

double variance(int *a, int n) {
    double mean = 0, square_mean = 0, variance = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++) {
        mean += (double)*p * probability;
        square_mean += (double)(*p * *p) * probability;
    }
    variance = square_mean - mean * mean;
    return variance;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}
