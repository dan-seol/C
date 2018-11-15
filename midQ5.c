#include <stdio.h>
void swap(int* i, int* j){
  int k;
  k = *i;
  *i = *j;
  *j = k;
}
 int main(void){
int a =2;
int b= 3;
int *temp = &a;
swap(temp, &b);
printf("%d %d %d \n", a, b, *temp);
return 0;

 }
