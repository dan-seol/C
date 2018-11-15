#include <stdio.h>
int main(void){
int j;
for(int i= 0; i< 300; i +=20){
  j = 5*(i-32)/9;
  printf("%d\t%d\n",i, j);
}
}
