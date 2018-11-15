#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 1024
int countlines( FILE *fin)
{
    int nlines = 0;
    char line[BUFFSIZE];

    while(fgets(line, BUFFSIZE, fin) != NULL)
    {
      nlines++;
    }
    return nlines;

}
int main(int argc, char *argv[])
{
FILE *file;
  file = fopen("test.txt", "r");
  printf("The number of lines in the test.txt would be %d\n", countlines(file));
}
