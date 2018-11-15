#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int array[argc-1];
  for(int pos=1; pos<argc; pos++)
      array[pos-1] = atoi(argv[pos]);

  for(int pos=0; pos<argc-1; pos++){
    int curr = array[pos];
    int min_pos = -1;
    int min_val = INT_MAX;
    for(int other_pos=pos; other_pos<argc-1; other_pos++){
      if(array[other_pos] < min_val){
        min_pos = other_pos;
        min_val = array[other_pos];
      }
    }
    array[min_pos] = curr;
    array[pos] = min_val;
  }
    for(int pos=0; pos<argc; pos++)
      printf("Array element %d is %d. \n", pos, array[pos]);
      return 0;

}
