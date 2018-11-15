#include <stdio.h>
#include <string.h>

int main(void){
    char *my_word_array[3] = {NULL, NULL, NULL};
    char first[100] = "one";
    my_word_array[0] = first;

    my_word_array[1] = "two";

    char third[100];
    third[0] = '3';
    my_word_array[2] = third;

  //  strcpy(my_word_array[3], "4");

    printf("The words are: %s %s %s. \n", my_word_array[0], my_word_array[1], my_word_array[2]);


}
