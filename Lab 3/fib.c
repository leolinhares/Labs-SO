#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long double *fibArray;

void* fibonacci(void *arg){
    long double final = *((long double*)arg);
    
    long double first = 0, second = 1;
    fibArray = (long double *) malloc(final*(sizeof(long double)));
    fibArray[0] = first;
    fibArray[1] = second;
    
    for (int counter = first; counter <= final; counter++) {
        
        long double next =  first + second;
        first = second;
        second = next;
        fibArray[counter+2] = next;
    }
    pthread_exit(0);
}

int main(){
    long double *p;
    long double final;
    printf("Type the quantity of fibonacci numbers to be generated: ");
    scanf("%Lf", &final);

    pthread_t fib_generator;
    pthread_create(&fib_generator, NULL, fibonacci, (void*)&final);
    pthread_join(fib_generator, NULL);

    for (int i = 0; i < final; i++) {
        printf("Element %d - %.0Lf\n", i+1, fibArray[i]);
    }
}