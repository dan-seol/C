#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ssv.h"
#include "linked.h"
#define SIZE 1024

int main(){
  int *idTracker = (int*) malloc(sizeof(int));
  float *balanceTracker = (float*) malloc(sizeof(float));
  FILE *fp = fopen("students.ssv", "r");
  char record[SIZE];

  while(fgets(record, 2*SIZE, fp) != NULL) {
  
    parse(record, idTracker, balanceTracker);
    printf("%d %f\n", *idTracker, *balanceTracker);
    //*idTracker=3;
    //*balanceTracker=20.0;
    findUpdate(*idTracker, *balanceTracker);  
  }
 prettyPrint();
  return 0;
}

