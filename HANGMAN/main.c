/*
   HANGMAN game to play on LINUX.
   Developed by..: TALES LIMA...
   */

/*---------------------------- BLIBLIOTEC ------------------------------*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include"menu.h"
#include"animal.h"
#include"profission.h"
#include"filmes.h"
#include"series.h"
/*--------------------------- ENUM --------------------------*/
enum menu_game {animals = 1, profession, films, serie,sair}choise;

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

        system("clear");
        profission();
        break;
      case 3:
       system("clear");
       filmes();
        break;
      case 4:
        system("clear");
        series();
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

