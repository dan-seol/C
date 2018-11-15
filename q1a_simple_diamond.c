#include <stdio.h>
#include <stdlib.h> // Used for atoi() function
#include <string.h> // Used for strlen() function
#include <math.h>
#define TRUE 1
#define FALSE 0


void line(int n, int m){
  for(int i=0; i<n; i++){
    if((n/2)-(m) < i && i <= n/2){
      printf("*");
    } else if(n/2< i && i  < (n/2 +m) ){
      printf("*");
    } else {
      printf(" ");
    }
  }
    printf("\n");
}

void diamond(int n)
{
  for(int i = 1; i <=(n/2)+1; i++){
    line(n, i);
  }
  for(int j = n/2; j >=1; j--){
    line(n, j);
  }
}

int main(int argc, char *argv[])
{

    //case separated when there are zero arguments
    if( argc > 2 ) {
         printf("ERROR: Wrong number of arguments. One required\n");
         return 1;
       }
       else if (argc < 2){
         printf("ERROR: Wrong number of arguments. One required\n");
         return 1;
       } else {

         int n = (int) strtol(argv[1], NULL, 10);
         if(n % 2 == 0  ){
           printf("ERROR: Bad argument. Height must be positive odd integer \n");
           return 1;
         }

         printf("%d\n", n);
         diamond(n);

    }

}
