/*
   HANGMAN game to play on LINUX.
   Developed by..: TALES LIMA.
   */

/*---------------------------- BLIBLIOTEC ------------------------------*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include"menu.h"
#include"animal.h"
/*----------------------- DECLARATION OF CONSTANTS ---------------------*/

/*------------------------------ ENUM ----------------------------------*/
enum menu_game {animals = 1, profession, films, serie,sair}choise;

/*----------------------- PROTOTYPE OF FUNCTIONS -----------------------*/

/*------------------------------- MAIN ---------------------------------*/
int main(int argc, char *argv[])
{
  int option, choise;
  setlocale(LC_ALL,"Portuguese");
  do {
    menu();
    scanf("%i",&option);
    setbuf(stdin,NULL);
    
    switch (option) {
      case 1:
        system("clear");
        animal();
        break;
      case 2:
        printf("profisaoo.....\n");
        break;
      case 3:
        printf("filmes.......\n");
        break;
      case 4:
        printf("serie .......\n");
        break;
      case 5:
        printf("Leaving......\n");
        break;
      default:
        printf("[ERROR] choose one of the numbers above..\n");
    }
  } while (option != 5);
  return 0;
}

