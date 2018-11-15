#include <stdio.h>

int main(void){
  int F, C;
  int lower, upper, step;

  lower = -20;
  upper = 300;
  step = 20;
  F = lower;
  while(F <= upper){
    C = 5*(F-32)/9;
    printf("%d\t%d\n", F, C);
    F += step;

  }
}
