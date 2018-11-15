#include <stdio.h>
#include <string.h>
//strcmp() : Compares the ascii value of the first unmatched character
//Compares two strings

int main(int argc, char* argv[]){
 if(argc != 3){
  printf("ERROR: please type in a string and a positive integer\n");
  return 0;
 }
 char s1[256];
 char s2[256];
 strcpy(s1, argv[1]);
 strcpy(s2, argv[2]);

 int ret = strcmp(s1, s2);

   if(ret < 0) {
      printf("s1 is less than s2\n");
      return 1;
   } else if(ret > 0) {
      printf("s2 is less than s1\n");
      return 1;
   } else {
      printf("s1 is equal to s2\n");
      return 1;
   }
}
