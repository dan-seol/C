#include <stdio.h>

int main(void){
  float F, C;
  int lower, upper, step;

  lower = -20;
  upper = 300;
  step = 20;
  F = lower;
  while(F <= upper){
    C = (5.0/9.0)*(F-32);
    printf("%3.2f\t%3.0f\n", F, C);
    F += step;

  }
}
