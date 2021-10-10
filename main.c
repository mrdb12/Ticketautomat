#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runMenu();
struct ticket *ini24HTicket();

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

  printf("Do you want to buy a ticket(1) or quit(2)\n");
  scanf("%c", &option);
  if(option == '1'){
    printf("Ticket choosen");
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
