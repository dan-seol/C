#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]){
const int array_length = 11;
float account_balances[array_length];
for(int pos=0; pos<array_length; pos++){
  account_balances[pos] = expf(pos);
  printf("The value of e to the power %d is %f \n", (pos), account_balances[pos]);
}

}
