#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_words(char *words[], int count)
{
  char *x;
  for(int i=0; i<count; i++)
  {
    for(int j= i+1; j<count; j++)
    {
      if(strcmp(words[i], words[j]) > 0)
      {
          x = words[j];
          words[j] = words[i];
          words[i] = x;
      }
    }
  }
}

#ifndef RunTests
int main(int argc, char *argv[])
{
  char *words[] = {"cherry", "orange", "apple"};
  sort_words(words, 3);

  for(int i=0; i<3; i++)
  {
    printf("%s", words[i]);
  }
}
#endif
