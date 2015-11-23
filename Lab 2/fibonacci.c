#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>


/* Calculates the k th fibonacci term */
long double fib(long double k){
    return (1/sqrt(5))*( pow(((1+sqrt(5))/2),k) - pow(((1-sqrt(5))/2),k));
}

int main(){

    long double *p;
    int initial, final;
    int i;

    printf("Type two numbers (starting from 1) separated by a space: ");
    scanf("%d %d", &initial, &final);
    while(initial<0 || final<0){
      printf("Invalid Input. Try again!\n");
      scanf("%d %d", &initial, &final);
    }

    long double array_size = final-initial+1;
    long double *array_fib = (long double *) malloc(array_size*(sizeof(long double)));


    for(i=initial;i<=final;i++){
      array_fib[i] = -2;
    }

    int aux = 0;
    for(i=initial;i<=final;i++){
      pid_t pID = fork();

      if(pID<0){
        printf("Fail\n");
      }
      else if(pID == 0){ //Child Process
        array_fib[aux] = fib(i-1);
        printf("Filho disse q fib %d eh -> %.0Lf\n",aux,array_fib[aux]);
        aux++;
        exit(0);
      }
      else{
        wait(0);
      }
    }
    for(i=initial;i<=final;i++){
      printf("%.0Lf\n",array_fib[i]);
    }
}
