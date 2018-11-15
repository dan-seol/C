#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
 if(argc != 3){
  printf("ERROR: please type in a string and a positive integer\n");
  return 0;
 }
 int arg2 = atoi(argv[2]);
 if(arg2 <1 ){
  printf("ERROR: please type in a strictly positive integer\n");
  return 0;
 }

 if(strlen(argv[1]) < arg2){
   printf("ERROR: your integer is longer than your string\n");
   return 0;
 }
 char str[256];
printf("Here is your string\n");
 strcpy(str, argv[1]);
 puts(str);

printf("I am going to change the first %d characters of your string into a dollar sign\n", arg2);

 memset(str, '$', arg2);
 puts(str);
 return 0;

}
