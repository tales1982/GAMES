/*------------------------ ANIMALS ------------------------------*/
#include<stddef.h>
#include<stdio.h>
#include<string.h>
/*----------------------- DECLARATION OF CONSTANTS ---------------------*/
#define EASY 12
#define MEDIUM 7
#define HARD 5

extern void animal();

void animal(void)
{
  /*==================== VARIAVEIS ==========================*/
  /*=======================================================*/
 

  char secret_word[] = "giraffe";
  int live = 0,option,score = 0,i,tam = 0,compara_string;
  tam = strlen(secret_word);
  char result[tam];
  memset(result,0, sizeof(result));//inizializa meu vetor com 0
  char lettre ;
  int easy = EASY, medium = MEDIUM, hard = HARD;
  /*------------------------ SUBMENU ---------------------------------*/
  printf("#==============================#\n");
  printf("#                              #\n");
  printf("#   Choose difficulty level    #\n");
  printf("#______________________________#\n");
  printf("#                              #\n");
  printf("#        1° - EASY             #\n");
  printf("#        2° - MEDIUM           #\n");
  printf("#        3° - HARD             #\n");
  printf("#                              #\n");
  printf("#==============================#\n");
  scanf("%i",&option);
  setbuf(stdin,NULL);
  system("clear");
  setbuf(stdin,NULL);

  if(option == 1){
    live = easy;
  }else if(option == 2){
    live = medium;
  }else if(option == 3){
    live = hard;
  }else{
    printf("[ERROR] choose one of the numbers above..\n");
    exit(1);
  }

  //-------------------- COMEÇO DO DO WHILE --------------------------
  do {
    printf("\nStill have [%i] chances.\t\tSCORE...: [%i]\n",live +1,score);
    printf("__________\n");
    printf("|.|       |\n");
    printf("|.|       |\n");
    printf("|.|      _|_\n");
    printf("|.|                     HANGMAN GAME\n");
    printf("|.|                   DEVELOPED BY TALES LIMA. \n");
    printf("|.|        \n");
    printf("|.|          \n");
    printf("|.|\n");
    printf("|.|\n");
    printf("|.|\n");
    printf("|.|\n\n\n");
    /*================== Entrada da letra ================= */
    printf("\ntype a letter...: ");
    scanf("%[^\n]",&lettre);
    setbuf(stdin,NULL);

    //ATE AQUI TA CERTO

    system("clear");
    for (i = 0; secret_word[i] != '\0'; ++i) {
//pecorre ate o final do secret_word (\o)..
      if(secret_word[i] == lettre){
        result[i] = secret_word[i];
        score += 10;
      }
      
        }
    printf("SECRET WORD..: ");
//Imprime o Nome caracter por caracter
    for (i = 0; i < tam; ++i) {
      putchar(result[i]);
      putchar('_');
       // printf(" %c_",result[i]);
      }
//solta uma linha
   printf("\n");
//compara se as 2 string sao iguais se sim retorna 0.   
   compara_string = strcmp(secret_word, result);
     
//Analiza se venceu o jogo
   if(compara_string == 0){
    
      printf("\n");
      printf("#=======================================#\n");
      printf("#                                       #\n");
      printf("#     Congratulation, you wim...        #\n");
      printf("#                                       #\n");
      printf("#    Secret word..: %s         #\n",secret_word);
      printf("#    YOU SCORE...: %i                  #\n",score);
      printf("#=======================================#\n\n");
      exit(1);
    }
//Analiza se perdeu o jogo
    if(live == 0){
    printf("\n");
    printf("#=======================================#\n");
    printf("#                                       #\n");
    printf("#              GAME OVER                #\n");
    printf("#                                       #\n");
    printf("#=======================================#\n\n"); 
    }
//
    live --;
  score -= 5;


  }while (live > -1);

}
/*
 printf("\n");
    printf("#=======================================#\n");
    printf("#                                       #\n");
    printf("#     %c                                 \n",result[i]);
    printf("#                                       #\n");
    printf("#=======================================#");
    
*/
