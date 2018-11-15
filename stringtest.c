#include <stdio.h>
int main(int argc, char *argv[]){
  char name[100] = "Daniel";
  char sis[100] = "Anne";
  char mom[100] = "Heewon";
  int c = 0;
  //char s[100];

 // gets(s); input from the user.
while (name[c] != '\0') {
printf("%c", name[c]);
c++;

}
printf("\n");
c=0;
while (sis[c] != '\0') {
printf("%c", sis[c]);
c++;

}
printf("\n");
c=0;
while (mom[c] != '\0') {
printf("%c", mom[c]);
c++;
}
printf("\n");
}
