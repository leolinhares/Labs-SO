#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define FIB_QUANTITY 60

long double * fibonacci(long double final){

    long double first = 0, second = 1;
    long double *fibArray = (long double *) malloc(final*(sizeof(long double)));
    fibArray[0] = first;
    fibArray[1] = second;

    for (int counter = first; counter <= final; counter++) {

        long double next =  first + second;
        first = second;
        second = next;
        fibArray[counter+2] = next;
    }
    return fibArray;
}

int main(){

    long double *p;
    long double initial, final;

    printf("Type two numbers (starting from 1) separated by a space: ");
    scanf("%Lf %Lf", &initial, &final);

    pid_t pID = fork();

    if(pID<0){
      perror("Fail\n");
    }
    else if(pID == 0){ //Child Process
      printf("\nChild Process!\n");
      printf("Type two numbers (from %.0Lf to %.0Lf) separated by a space: ",initial,final);
      scanf("%Lf %Lf", &initial, &final);
      p = fibonacci(final+1);
      for (int i = initial-1; i < final; i++) {
          printf("Element %d - %.0Lf\n", i+1, p[i]);
      }
    }
    else{
      wait(NULL);
      p = fibonacci(final+1);
      for (int i = initial-1; i < final; i++) {
          printf("Element %d - %.0Lf\n", i+1, p[i]);
      }
    }
}
