#include <stdio.h>
void swap(int* i, int* j){
  int k;
  k = *i;
  *i = *j;
  *j = k;
}
int main(int argc, char* argv[]) {
int x = 3;
int y = 4;
int* a = &x;
int* b = &y;
swap(a, b);
printf("%d, %d\n", *a, *b);
return 0;
}
