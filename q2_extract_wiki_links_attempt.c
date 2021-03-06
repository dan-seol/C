#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


//char article[20] = "<a href= \"/wiki/";
//char title[7] = "title=";
//char quote[2] = "\"";

//const char* filename = arg;
//char *ref;
//char *token1;
//char *token2;

int main(int argc, char *argv[]){

for(int i =1; i<argc; i++){
const char* fname= argv[i];
//create a file pointer
FILE *fp;

//open the file and have the file pointer point to it
fp = fopen(fname, "r+");

//print an error message if fp is null
if(fp == NULL){
    printf("ERROR: There is an error with the file.");
    return -1;
}



//copy the file contents to the file
char s[INT_MAX/2];
fread(s, 1, INT_MAX/2-2, fp);
s[INT_MAX/2-1] = '\0';



//set the start of the open pointer to the beginning of the haystack
char *open = s;

//this keeps track of the open pointer
char *timeStamp = open;

//pointers to be used in the while loop
char *close;
char *innerOpen;
char *innerClose;


//use a while loop to iterate through the whole file
while(1){

    //set open to the next occurance of "<a href ..."
    open = strstr(timeStamp, "<a href=\"/wiki/" );
    //break the loop if open is null
    if(open == NULL){
        break;
    }

    //set close to the next occurance of "</a>"
    close= strstr(open,"</a>");
    //break the loop if close is null
    if(close == NULL){
        break;
    }

    //create a char array labRat that is the size of the difference of the pointers
    size_t sizelabRat = close - open;
    char labRat[sizelabRat];

    //copy the characters between the pointers open and close into labRat
    strncpy(labRat, open, close - open);
    labRat[sizelabRat] = '\0';

    char *c;
    //test to see if there is another occurance between "<a href... " in the labRat
    if((c = strstr(labRat + 16, "<a href=\"/wiki/" )) != NULL){

        timeStamp = open + 16;
        continue;

    }

    //look for "title=\" and "\>" in the string array
    innerOpen = strstr(open, "title=\"");
    innerClose = strstr(innerOpen, "\">");


    //if "title=\" is in labRat, get the name and print it
    if(innerOpen != NULL && innerClose != NULL){
        size_t sizeInner = innerClose - (innerOpen + 7);
        char pageName[sizeInner];
        strncpy(pageName, innerOpen + 7, innerClose - (innerOpen + 7));
        pageName[sizeInner] = '\0';

        printf("%s \n", pageName);
    }

    //increase the position of the timeStamp by 15 (the length of "<a href ...")
    timeStamp = open + 16;

}
}
}



  //FILE *fp = fopen(argv[1],"r");

  //while(fgets(s, 9000, fp)){
  //  ref = strstr(s, article);
  //  token1 = strstr(ref, title);
  //  token2 = strtok(token1, quote);
  //  printf("%s\n", token2);
