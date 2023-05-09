/*------------------------ BIBLIOTECAS ------------------------*/
#include<stdlib.h>
#include<stdio.h>
#include"pac_man.h"
#include"mapa.h"


/*------------------- VAREAVEIS GLOBAL ------------------------*/
  
  MAPA m;
  POSICAO heroi;


/*=================== Declaracao de funcao ======================*/
 
 int acabou();
 void move(char direcao);

/*======================== MAIN ==================================*/
int main(int argc, char *argv[])
{

lemapa(&m);
encontramapa(&m, &heroi, '@');

do {
 imprimemapa(&m);

 char comando;
 scanf(" %c",&comando);
 setbuf(stdin,NULL);
 move(comando);
  
} while (!acabou());

liberamapa(&m);

return 0;
}

/*==============================================================*/



/*------------------------- ACABOU ---------------------*/
int acabou(){
 
  return 0;
}

/*-------------------------- MOVIMENTO -----------------*/
void move(char direcao){
 int x;
 int y;

 m.matriz[heroi.x][heroi.y] = '.';
 switch (direcao) {
   case 'a':
     m.matriz[heroi.x][heroi.y-1] = '@';
     heroi.y--;
     break;
    case 'w':
     m.matriz[heroi.x-1][heroi.y] = '@';  
     heroi.x--;
      break;
    case 's':
      m.matriz[heroi.x+1][heroi.y] = '@';
      heroi.x++;
      break;
    case 'd':
      m.matriz[heroi.x][heroi.y+1] = '@';
      heroi.y++;
      break;
 }

}
