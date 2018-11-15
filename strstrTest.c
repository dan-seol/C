#include <stdio.h>
#include <string.h>


int main (int argc, char* argv[]) {
   char haystack[256];
   char needle[256];
   if(argc != 3){
   printf("ERROR: Please type in two strings");
   return 1;
   }

  strcpy(haystack, argv[1]);
  strcpy(needle, argv[2]);
  if(strlen(haystack) < strlen(needle)){
    printf("ERROR: Your \" substring \" is longer than the original string to be compared");
  }
   char *ret;

   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);

   return(0);
}
