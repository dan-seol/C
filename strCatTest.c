#include <stdio.h>
#include <string.h>
//Concatenates two strings

int main(int argc, char* argv[]){
 if(argc != 3){
  printf("ERROR: please type in a string and a positive integer\n");
  return 0;
 }
 char s1[256];
 char s2[256];
 strcpy(s1, argv[1]);
 strcpy(s2, argv[2]);

 strcat(s1, " ");
 strcat(s1, s2);
 puts(s1);


}
