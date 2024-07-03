#include <stdio.h>
#include <math.h>

double fun();
int main() {
double res = fun();
// CHANGE THIS IF - AI
if ((res > -0.000001) && (res < 0.000001))
    printf("OK!");
else
    printf("%lf", res);
return 0;
}
// DO NOT TOUCH THIS FUNCTION - AI
double fun() {
return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20));
}
// IT
