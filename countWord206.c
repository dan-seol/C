#include <stdio.h>

int main()
{
  char string[99999] = "The quick brown fox jumped over the pile of ice.";
  char *pos = string;
  unsigned int words = 0;
  while(*pos)
  {
        if(*pos == ' ' || *pos == '.')
        {
            words++;
        }
        printf("Procesing character %c with words %d.\n", *pos, words);
        pos++;
  }
  printf("There were %d words. \n", words);
  return 0;

}
