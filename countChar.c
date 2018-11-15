#include <stdio.h>
int main(int argc, char *argv[]){
  char s[100] = "Rahman";
  char t[100];
  int a = 0;
  int b = 0;
  printf("Type in a word:");
  fgets(t, 99, stdin);
  while(s[a] != '\0'){
  a++;
  }
  while(t[b] != '\0'){
  b++;
  }

  printf("The word \'Rahman\' has %d characters\n", a);
  printf("The word you typed has %d characters", b-1);
  return 0;
}
