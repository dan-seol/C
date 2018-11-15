#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
// It can take multiple downloaded pages at once.
//EXAMPLE OUTPUT from
// $  ./a.out Bird Jurassic
//

int main(int argc, char* argv[]){
  for(int i =1; i<argc; i++){
    printf("Here is your %d-th article.", i);
    char* fname = argv[i];
    FILE *fpointer;

    fpointer = fopen(fname, "r+");
    if(fpointer == NULL){
        printf("ERROR MESSAGE: The file does not exist");
        return -1;
    }
    size_t l;
    fseek(fpointer, 0 , SEEK_END);
    l = ftell(fpointer);
    rewind(fpointer);

    char s[l+1];
    fread(s, 1, l+1, fpointer);
    s[l] = '\0';
    char *begin = s;
    char *timeStamp = begin;
    char *end;
    char *nestedBegin;
    char *nestedEnd;


    //We iterate through the whole file
    while(1)
    {

     begin = strstr(timeStamp, "<a href=\"/wiki/");
        if(begin == NULL)
        {
            break;
        }
        end= strstr(begin,"</a>");
        if(end == NULL)
        {
            break;
        }
        size_t sizelabRat = end - begin;
        char labRat[sizelabRat];
        strncpy(labRat, begin, sizelabRat);
        labRat[sizelabRat] = '\0';
        char *d;
        if((d = strstr(labRat + 18, "<a href=\"/wiki/" )) != NULL)
        {timeStamp = begin + 18;
          continue;

        }
        nestedBegin = strstr(begin, "title=\"");
        nestedEnd = strstr(nestedBegin, "\">");
        if(nestedBegin != NULL && nestedEnd != NULL)
        {size_t nestedSize= nestedEnd - (nestedBegin + 7);
          char pageTitle[nestedSize];
          strncpy(pageTitle, nestedBegin + 7, nestedEnd - (nestedBegin + 7));
          pageTitle[nestedSize] = '\0';

            printf("%s \n", pageTitle);
        }
        timeStamp = begin + 18;
        printf("\n");

    }
      fclose(fpointer);

    }
  return 0;
}
