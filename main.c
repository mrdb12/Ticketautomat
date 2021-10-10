#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runMenu();
struct ticket *ini24HTicket();
struct ticket *iniOneTimeTicket();
void printTicket(struct ticket *ticket);


struct ticket{
  char name[15];
  double price;
};

int main(void){
  runMenu();

  return 0;
}

void runMenu(){
  char option;
  struct ticket *ticket;

  printf("Do you want to buy a ticket(1) or quit(2)\n");
  scanf("%c", &option);
  if(option == '1'){
    printf("Which ticket do you want to buy?:\n24HTicket (1)\nOneTimeTicket (2)\n");
    scanf("\n%c", &option);
    if (option == '1') {
      ticket = ini24HTicket();
      printTicket(ticket);
    }else if (option == '2') {
      ticket = iniOneTimeTicket();
      printTicket(ticket);
    }else{
      printf("Illegal input\n");
    }
  }else if(option == '2'){
    printf("Quiting");
  }else{
    printf("Illegal input\n");
  }

}

struct ticket *ini24HTicket(){
  struct ticket *ptrTicket;
  ptrTicket = (struct ticket *) malloc(sizeof(struct ticket));
  strcpy(ptrTicket->name, "24HTicket" );
  ptrTicket->price = 8.8;

  return ptrTicket;
}

struct ticket *iniOneTimeTicket(){
  struct ticket *ptrTicket;
  ptrTicket = (struct ticket *) malloc(sizeof(struct ticket));
  strcpy(ptrTicket->name, "OneTimeTicket");
  ptrTicket->price = 3.3;

  return ptrTicket;
}

void printTicket(struct ticket *ticket){
  printf("....................\n");
  printf("You bought the ticket: %s\n", ticket->name);
  printf("For %.2f $\n", ticket->price);
  printf("....................\n");
}
