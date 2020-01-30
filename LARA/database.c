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
  printf("##################### DATABASE DISPLAY:END #####################\n");
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
   } else {
    isDetected = 1;
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

char* strUpp(char * lower){
  char* name = malloc(1024);
  strcpy(name, lower);
  char *s = name;

  while(*s) {
  
    *s = toupper((unsigned char)*s);
    s++;
  
  }

  return name;
 
}

int main(int argc, char* argv[]){

  //Opening the file for reading
  /*
  delRecords("dan");
  showRecords();
  addRecords(25, "dan", 22, 3.8);
  showRecords();
  */
  if(argc < 2){
  
    printf("You did not provide any arguments.\nPlease enter: ./database CMP OPT1 OPT2 OPT3 OPT4\n");
    return 1;
  }

  char * CMD  = strUpp(argv[1]);
  
  int isSHOW = (strcmp(CMD, "SHOW") == 0);
  int isADD = (strcmp(CMD, "ADD") == 0) ;
  int isDELETE = (strcmp(CMD, "DELETE") == 0);
  if(!isSHOW && !isADD && !isDELETE ) {

    printf("The command you requested is invalid.\n Please select from one of these: SHOW, DELETE, ADD\n");
    printf("The command you typed is (capitalized) : %s\n",CMD);    
    return 1;

  }else if(isSHOW){
    if(argc != 2){
    printf("You typed unnecessary argument with SHOW\n");
    return 1;
    }
    printf("Showing records:\n");
    showRecords();
  
  }else if(isDELETE){
    if(argc == 2){
      printf("The name of the record to delete is missing\n");
      return 1;
    }
    int isDetected = delRecords(argv[2]);
      if(isDetected == 0){
      printf("Sorry, that user was not found. Nothing was deleted\n");
      return 1;
      }

      printf("The record of the user %s was deleted \n", argv[2]);
  } else {
    if(argc < 5){
    
      printf("Missing ID, Name, AGE, and GPA arguments");
      return 1;
    }
    int ID = (int) strtol(argv[2], NULL, 10);
    int AGE = (int) strtol(argv[4], NULL, 10);
    double GPA = strtod(argv[5], NULL);
    addRecords(ID, argv[3], AGE, GPA);
    printf("A new record with ID=%d, NAME=%s, AGE=%d, GPA=%.1f has been added\n",ID, argv[3], AGE, GPA);  

  }
  return 0;

}


