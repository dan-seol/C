#include <stdio.h>
 int cumsum(int a, int b){ // returns the sum_{i=a}^{b} i
   int val = 0;
   for(int i = a; i < b+1; i++){
     val += i;
   }
   return val;
 }
  int main(void){
    printf("The sum of all integers from %d to %d is %d\n", 3, 10, cumsum(3,10));
    printf("The sum of all integers from %d to %d is %d\n", 6, 17, cumsum(6,17));
  }
  //function components
  // a return type
  // a fileName
  // an argument List
  // a function body list
  //the name must be unique
  //pass arguments by values
  //define a local scope
