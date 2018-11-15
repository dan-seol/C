#include <stdio.h>
#include <math.h>
int power2(int m){
  if(m==0){
    return 1;
  } else if (m < 0) { // positive integer assumes
    printf("This functions is defined for nonnegative integers only");
    return -1;
  } else {
    return 2*power2(m-1);
  }

}

int main(void){
  int n = 5;
  printf("%d\n", n/2);
  int m= 9;
  printf("%f %d\n",log2(m), (int)(log2(m)));
  printf("%d\n", (log2(m) - (int)log2(m) ==0));
  printf("%d\n", power2(0));
  printf("%d\n", power2(2));
  printf("%d\n", power2(3));
}
