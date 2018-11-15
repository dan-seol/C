#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  int l;
  l = atoi(argv[1]);

  for(int i=2; i<argc; i= i + 2){
      if(strcmp(argv[i], "+")==0){
      l = l + atoi(argv[i+1]);
    } else if (strcmp(argv[i], "-")==0){
      l = l-atoi(argv[i+1]);
    } else if(strcmp(argv[i], "x")==0){
      l = l*atoi(argv[i+1]);

    }else if(strcmp(argv[i], "/")==0){
      l =  l/atoi(argv[i+1]);
    } else{
      printf("ERROR: I did not understand");
      return -1;
      }
  }
printf("%d", l);
return 0;

}
