#include <stdio.h>
int main(int argc, char *argv[]){
int array[4] = {1,2,3,4};
for(int i=0; i<100; i++){
 printf("%d, %d", i, array[i]);
}
}
