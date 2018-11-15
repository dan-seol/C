#include <stdio.h>
#include <string.h>
int words(const char sentence[])
{
  int counted = 0; // result
  // state:
  const char* it = sentence;
  int inword = 0;
  do switch(*it)
  {
    case '\0':
    case ' ': case '\t': case '\n': case '\r': // TODO others?
      if (inword){inword = 0; counted++;}
      break;
      default: inword =1;
  } while(*it++);
  return counted;
}

int main(int argc, const char *argv[])
{
    char t[2000];
    fgets(t, 2000, stdin);
    printf("%d\n", words(t));
    printf("%d\n", words(""));
    printf("%d\n", words("\t"));
    printf("%d\n", words("   a    castle"));
    printf("%d\n", words("my world is a castle"));
}
