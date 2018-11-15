#include <stdio.h>
int main(void){
unsigned char c = 'c';
unsigned char d = ( c >> 3 ) << 3;
printf("%c\n", c);
printf("%c\n", d);
unsigned char e = c * 8;
printf("%c\n", c >> 2);
printf("%c\n", c << 2);
return 0;
}
