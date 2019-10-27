#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getLength(char* str) {

	int length = 0;
	char* pos = str;
	while (*pos) {
		//Every string in C is stored as an array of char's. e.g. "Hello" is stored as {'H', 'E', 'L', 'L', 'O', '\0'}.
		//Something to take away is that the pointer (in our case, it will be *pos) towards '\0' will be evaluated as zero.
		pos++;
		length++;

	}
	return length;

}

int main(int argc, char* argv[]){
  
  if(argc !=3){
    
    printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2\n");
    return 1;

  } else {
  
    int length1 = getLength(argv[1]);
    int length2 = getLength(argv[2]);
    int numberOfMatchingCharacters = 0;

    char word1[1024];
    char word2[1024];
    char word2flipped[1024];
    for(int l1 = 0; l1 <length1+1; l1++){
    
      word1[l1] = argv[1][l1];

    }

    for(int l2 = 0; l2< length2+1; l2++){
    
      word2[l2] = argv[2][l2];

    }

    for(int i = 0; i<length2; i++){
      
      word2flipped[i] = word2[length2-1-i];
    
    }
    
    word2flipped[length2] = '\0';

    if(length1 != length2){
    
      printf("WORD1=%s WORD2=%s - NOT REVERSE", word1, word2);
      return 0;
    
    } else {
  
      for(int j=0; j<length1; j++){

        if(word1[j]==word2flipped[j]){
          
          numberOfMatchingCharacters++;
        
        }
      }

      if(numberOfMatchingCharacters==length1){
      
        printf("WORD1=%s WORD2=%s - REVERSE", word1, word2);
        return 0;

      } else {
    
        printf("WORD=%s WORD2=%s - NOT REVERSE", word1, word2);
        return 0;
      
      }
    }
  }
}
