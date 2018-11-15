#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void){
  float F, C;
  int lower, upper, step;


  F = LOWER;
  while(F <= UPPER){
    C = (5.0/9.0)*(F-32);
    printf("%3.2f\t%3.3f\n", F, C);
    F += STEP;

  }
}
