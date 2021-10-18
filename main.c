#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printInfo();
struct ticket * runMenu();
struct ticket *ini24HTicket();
struct ticket *iniOneTimeTicket();
void printTicket(struct ticket *ticket);
struct ticket *chooseTicket();
int payTicket(struct ticket *ticket);
struct ticket *append(struct ticket *currEnd, struct ticket *newTicket);//returns new end
void printLinkedList(struct ticket *start);
void appendTickets(char filename[30], struct ticket *start);



struct ticket{
  char name[15];
  double price;
  struct ticket *next;
};

int main(void){
  int bool = 1;
  struct ticket *tickets;

  while(bool){
    //Datum
    tickets = runMenu();
    appendTickets("log.txt", tickets);
  }

  return 0;
}

void printInfo(){
  printf("\nTickets: \n24HTicket: 8.8$");
  printf("\nOneTimeTicket: 3.3$\n");
}

struct ticket * runMenu(){ //returns start of ticket list
  struct ticket *ticket = NULL;
  struct ticket *tickets = NULL;
  struct ticket *end;
  char option;
  int bool = 1;

  printf("\nHello and welcome to your ticket machine\n");

  while(bool){
    printf("\nDo you want to buy a ticket(1), pay(2), info(3), quit(4)\n");
    scanf("\n%c", &option);

    if(option == '1'){
      ticket = chooseTicket();
      printf("You chose the %s\n", ticket->name);

      if(tickets != NULL){
        end->next = ticket;
        end = ticket;
      }else{
        tickets = end = ticket;
      }

    }else if(option == '2'){
      if(payTicket(tickets)){
        break;
      }
    }else if(option == '3'){
      printInfo();
    }else if(option == '4'){
      tickets = NULL;
      break;
    }
    else{
      tickets = NULL;
      printf("Illegal input\n");
    }
  }
  printf("Have a nice day\n\n");

  return tickets;
}

struct ticket *ini24HTicket(){
  struct ticket *ptrTicket;
  ptrTicket = (struct ticket *) malloc(sizeof(struct ticket));
  strcpy(ptrTicket->name, "24HTicket" );
  ptrTicket->price = 8.8;
  ptrTicket->next = NULL;

  return ptrTicket;
}

struct ticket *iniOneTimeTicket(){
  struct ticket *ptrTicket;
  ptrTicket = (struct ticket *) malloc(sizeof(struct ticket));
  strcpy(ptrTicket->name, "OneTimeTicket");
  ptrTicket->price = 3.3;
  ptrTicket->next = NULL;

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
  printf("\n....................\n");
  printf("Ticket: %s\n", ticket->name);
  printf("For %.2f $\n", ticket->price);
  printf("....................\n\n");
}

int payTicket(struct ticket *ticket){
  int check = 0;
  double price = 0;
  double cashInput = 0;
  double cashCurrInput;
  double change;
  struct ticket *ptr = ticket;

  while(ptr!=NULL){
    price += ptr->price;
    ptr = ptr->next;
  }

  while(price > cashInput){
    printf("\n");
    printf("You still have to pay: %.2f\n", (price-cashInput));
    printf("Or do you want to exit, if so write a negative number\n");
    scanf("\n%lf", &cashCurrInput);

    if(cashCurrInput >= 0){
      cashInput += cashCurrInput;
    }else{
      if(cashInput > 0){
        printf("\nChange: %.2f\n", cashInput);
      }
      break;
    }
  }
  if(price < cashInput){
    check = 1;
    change = cashInput - price;
    ptr = ticket;

    while(ptr!=NULL){
      printTicket(ptr);
      ptr = ptr->next;
    }
    printf("\nChange: %.2f\n", change);
  }

  return check;
}

struct ticket *append(struct ticket *currEnd, struct ticket *newTicket){ //returns new end
  currEnd->next = newTicket;
  return newTicket;
}

void printLinkedList(struct ticket *start){
  struct ticket *ptr = start;

  while(ptr != NULL){
    printf("--Ticketname: %s\n", ptr->name);
    ptr = ptr->next;
  }
}

void appendTickets(char filename[30], struct ticket *start){
  FILE *ofile;
  ofile = fopen(filename, "a");
  struct ticket *ptr = start;

  while(ptr!=NULL){
    fprintf(ofile, "%s %.2f\n", ptr->name, ptr->price);
    ptr = ptr->next;
  }

  fclose(ofile);
}
