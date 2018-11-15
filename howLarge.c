#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   FILE *fp = fopen("file.txt","r");
  size_t sz;
  fseek(fp, 0L, SEEK_END);
  sz = ftell(fp);
  rewind(fp);

  char file_data_array[sz+1];
  fread(file_data_array, 1, sz+1, fp);
  printf("File contents:\n%s\n", file_data_array);
  printf("%lu\n", strlen(file_data_array));
  for(int pos = 0; pos<sz+1; pos++){
    printf("Character %d has AASCI value %d.\n", pos, file_data_array[pos]);
  }
  while(fgetc(fp) !=EOF){
    printf("I read the character %c. \n", fgetc(fp));
  }
  printf("%lu\n", strlen("We are in 2012"));

   return(0);
}
