#include <stdio.h>
int main(int argc, char *argv[]){
  printf("I have %d arguments\n", argc);
  printf("The zeroth arg is %s\n", argv[0]);
  for(int i = 1; i <3 ; i++){
  //printf("The 1st arg is %s", argv[1]);
  printf("The %d -th arg is %s\n",i, argv[i]);
 }
}
