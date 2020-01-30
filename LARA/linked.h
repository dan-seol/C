#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ACCOUNT {
  int accountNumber;
  float balance;
  struct ACCOUNT *next;
} ACCOUNT;

static ACCOUNT *head = NULL;
static ACCOUNT *tail = NULL;

void findUpdate(int account, float amount) { //you mean float amount, right?
  
  ACCOUNT *current = (ACCOUNT *) malloc(sizeof(ACCOUNT));
  if(head == NULL ){
    
    current->accountNumber = account;
    current->balance = amount;
    current->next = NULL;          
    head = current;
    tail = current;


  } else {
  
    current=head;
  
  

  while(current != NULL) {
  
    if(current->accountNumber == account){
    
      current->balance += amount;
      return;

    }

    if(current->next == NULL){
    ACCOUNT *newAccount = (ACCOUNT*) malloc(sizeof(ACCOUNT));
    newAccount->accountNumber = account;
    newAccount->balance = amount;
    newAccount->next = NULL;          
    current->next = newAccount;
    return;

 
    }
    current = current->next;
  
  }
  
}

}

void prettyPrint() {

  ACCOUNT *current = head;
  printf("######################### ACCOUNT RECORDS BELOW #########################\n");
  while(current != NULL) {
  
    printf("[ ACCOUNT ID: %-5d     BALANCE: $ %-6.2f ]\n", current->accountNumber, current->balance);
    
    current = current->next;

  }
  printf("######################### ACCOUNT RECORDS ABOVE #########################\n");

}
