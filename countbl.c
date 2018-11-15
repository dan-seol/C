#include <stdio.h>
/* count characters in input; 2nd version */
int main(int argc, char* argv[]){

int c, n1;
n1 = 0;
while ((c = getchar()) != EOF)
{
if(c == '\n'|| c == ' ' || c == '\t'){
++n1;
}
printf("%d\n", n1);
}
return 0;
}
