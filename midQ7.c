#include <stdio.h>
int main(void)
{
int i=2;
int x =3;
while(1){
x = x+x;
break;

}
for(i = i+i; i<x; x++){
  i = i+i;
}
printf("%d %d\n", x, i);
return 0;

}
