#include<stdio.h>
#include<math.h>
#include"activation.h"
double f(double x) {
    return  .3*x*x*x-2*x*x+1.5*x+4 + .2*x*x*x*x;
}


double derivative_of_f(double x) {
    return 3*.3*x*x-4*x+1.5 + 4*.2*x*x*x;
}

int main() {
    activation actv;
    actv.f = f;
    actv.d = derivative_of_f;

    double extreme = calculate_extreme(&actv,.1);
    printf("calculated extreme: %f", extreme);
}

