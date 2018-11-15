#include <stdio.h>

void muddle(char string[]){

  string[0] =  'M' + 1;
  string[1] = string[1];
  string[2] = string[1];

  char temp = string[4];
  string[4] = string[5];
  string[5] = temp;
}
int main(void){
char string[10] = "goedel";
muddle(string);
printf("%s\n", string);
return 0;

}
