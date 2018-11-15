#include <stdio.h>
int main(int argc, char *argv[]){
   char s[100] = "Hello World";
   int c = 0;
   int e = 0;
   char t[100];
   fgets(t, 99, stdin);
   while(s[c]!= '\0'){
     c++;
   }
   while(t[e]!= '\0'){
     e++;
   }

   for(int d = c-1; d >= 0; d--){
   printf("%c", s[d]);
   }
   printf("\n");
   for(int f = e-1; f >= 0; f--){
   printf("%c", t[f]);
   }
   printf("\n");
   return 0;
}
