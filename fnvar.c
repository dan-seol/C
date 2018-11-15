#include <stdio.h>
  int increment(int fnvar){
  fnvar++;
  return fnvar;
}
int main(){
  int a=5;
   increment(a);
  printf("The value of a is now %d\n", a);
  int b=5;
  b = increment(b);
  printf("The value of b is now %d\n", b);
}
