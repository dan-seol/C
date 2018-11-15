#include <stdio.h>

#define IN 1 /*inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main(int argc, char*argv[]){

    int c, nl, nw, nc, state;
    state=OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
      ++nc;
      putchar(c);
      if(c=='\n'){
        ++nl;
      }
      if(c == '\n' || c == ' ' || c == '\t'){
        state = OUT;
      } else if (state == OUT){
        state = IN;
        ++nw;
        printf("\n");
      }
    }


}
