#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printInfo();
struct ticket * runMenu();
struct ticket *ini24HTicket();
struct ticket *iniOneTimeTicket();
void printTicket(struct ticket *ticket);
struct ticket *chooseTicket();
int payTicket(struct ticket *ticket);

struct ticket{
  char name[15];
  double price;
};

int main(void){
  struct ticket *ticket;

  //Routenplaner
  //Infos Printen
  ticket = runMenu();
  payTicket(ticket);
  //Mehrere Karten kaufen
  //Protokoll ausschreiben

  //Abbruch möglichkeit

  return 0;
}

void printInfo(){
  printf("\nTickets: \n24HTicket: 8.8$");
  printf("\nOneTimeTicket: 3.3$\n");
}

struct ticket * runMenu(){
  struct ticket *ticket = NULL;
  char option;

  printf("Do you want to buy a ticket(1), quit(2) or info(3)\n");
  scanf("%c", &option);

  if(option == '1'){
    ticket = chooseTicket();
  }else if(option == '2'){
    printf("Quiting");
  }else if(option == '3'){
    printInfo();
  }else{
    printf("Illegal input\n");
  }

  return ticket;

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

struct ticket *chooseTicket(){
  struct ticket *ticket = NULL;
  char option;

  printf("Which ticket do you want to buy?:\n24HTicket (1)\nOneTimeTicket (2)\n");
  scanf("\n%c", &option);
  if (option == '1') {
    ticket = ini24HTicket();
  }else if (option == '2') {
    ticket = iniOneTimeTicket();
  }else{
    printf("Illegal input\n");
  }

  return ticket;
}

void printTicket(struct ticket *ticket){
  printf("....................\n");
  printf("You bought the ticket: %s\n", ticket->name);
  printf("For %.2f $\n", ticket->price);
  printf("....................\n");
}

int payTicket(struct ticket *ticket){
  int check = 0;
  double price = ticket->price;
  double cashInput = 0;
  double cashCurrInput;
  double change;

  while(price > cashInput){
    printf("\n");
    printf("You still have to pay: %.2f\n", (price-cashInput));
    printf("Or do you want to exit, if so write a negative number\n");
    scanf("\n%lf", &cashCurrInput);

    if(cashCurrInput >= 0){
      cashInput += cashCurrInput;
    }else{
      break;
    }
  }
  if(price < cashInput){
    check = 1;
    change = cashInput - price;
    printTicket(ticket);
    printf("\nChange: %.2f\n", change);
  }

  return check;
}
