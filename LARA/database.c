#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 1024

typedef struct Record {
  int ID;
  char NAME[SIZE];
  int AGE;
  double GPA;
} Record;

typedef struct node {
  Record val;
  struct node *next;
} node_r;

void trimSpace(const char *input, char *result) {

    int i, j = 0;
    for (i=0; input[i] != '\0'; i++) {
      if(!isspace((unsigned char)input[i])) {
        result[j] = input[i];
        j++;
      }
    }
    result[j] = '\0';
    
}
void showRecords() {
  FILE *fp = fopen("database.csv", "r");
  char db1[SIZE];
  
  printf("#################### DATABASE DISPLAY:START ####################\n");
  int row = 1;
  while(fgets(db1, 2*SIZE, fp) != NULL) {

    char lineTrimmed[SIZE];
    trimSpace(db1, lineTrimmed);
    //printf("%s\n", lineTrimmed);
    Record *record = malloc(sizeof(Record));
    char * tok;
    tok = strtok(lineTrimmed,",");
    record->ID = (int) strtol(tok, NULL, 10);
    tok = strtok(0, ",");
    strcpy(record->NAME, tok);
    tok=strtok(0,",");
    record->AGE = (int) strtol(tok, NULL, 10);
    tok=strtok(0,",");
    record->GPA = strtod(tok, NULL);
    printf("Record %d : [ ID = %d, NAME = %s, AGE = %2d, GPA = %.1f ]\n", row, record->ID, record->NAME, record->AGE, record->GPA);
    row++;
    free(record);
  }
   fflush(fp);
   fclose(fp);
  printf("#################### DATABASE DISPLAY:END ####################\n");
  }

void addRecords(int newId, char* newName, int newAge, double newGpa) {

  FILE *fp = fopen("database.csv", "a+");
  fprintf(fp, "%d, %s, %d, %.1f\n", newId, newName, newAge, newGpa);
  fflush(fp);
  fclose(fp);
}

int delRecords(char* nameToDel){
  int isDetected = 0;
  FILE *fp = fopen("database.csv", "r");
  FILE *result = fopen("database.tmp", "w");
  char db1[SIZE];
  
  while(fgets(db1, 2*SIZE, fp) != NULL) {

    char lineTrimmed[SIZE];
    trimSpace(db1, lineTrimmed);
    Record *record = malloc(sizeof(Record));
    char * tok;
    tok = strtok(lineTrimmed,",");
    record->ID = (int) strtol(tok, NULL, 10);
    tok = strtok(0, ",");
    strcpy(record->NAME, tok);
    tok=strtok(0,",");
    record->AGE = (int) strtol(tok, NULL, 10);
    tok=strtok(0,",");
    record->GPA = strtod(tok, NULL);
    
   if(strcmp(record->NAME, nameToDel) !=0) {
    fprintf(result, "%d, %s, %2d, %.1f\n", record->ID, record->NAME, record->AGE, record->GPA);
   }
    free(record);

  }
   fflush(fp);
   fclose(fp);
   fflush(result);
   fclose(result);
   system("rm database.csv");
   system("mv database.tmp database.csv");
 
  return isDetected;

}

int main(){

  //Opening the file for reading
  delRecords("dan");
  showRecords();
  addRecords(25, "dan", 22, 3.8);
  showRecords();
  
  return 0;

}


