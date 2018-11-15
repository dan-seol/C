#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

for(int i = 1; i< argc; i++){
     int length = 0;
      char* pos = argv[i];
      while(*pos){ // the pointer towards \0 gets to be evaluated as zero
        pos++;
        length++;
      }
        printf("The %d-th string %s has length %d. \n", i, argv[i], length);
  }
}
