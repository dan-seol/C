#include <stdio.h>

int* f( int size, int *ptr ){

    int array[size];

    array[0] = 1;

    return ptr;

}

int main(){

    int i = 5;

    int *p = f( i, &i );

    i = p[0];

    printf( "The value of i is %d.\n", i );

    return 0;

}
