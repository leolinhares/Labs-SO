#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Calculates the k th fibonacci term */
long double fib(long double k){
    return (1/sqrt(5))*( pow(((1+sqrt(5))/2),k) - pow(((1-sqrt(5))/2),k) );
}


/* Generates a fibonacci sequence from an initial value ini to a final value end */
long double * fibonacci(long double ini, long double end){
    
    long double array_size = end-ini+1;
    long double *array_fib = (long double *) malloc(array_size*(sizeof(long double)));
    
    //array_fib will be filled starting with the first position (zero)
    int i = 0;
    for (int value = ini; value <= end; value++) {
        array_fib[i] = fib(value);
        i++;
    }
    return array_fib;
}

int main(){
    long double *p;
    long double initial, final;
    printf("Type two numbers starting from 1 (fibonacci range) separated by a space: ");
    scanf("%Lf %Lf", &initial, &final);
    
    p = fibonacci(initial-1, final-1);
    for (int i = 0; i <= (final-initial); i++) {
        printf("%.0Lf\n", p[i]);
    }
}