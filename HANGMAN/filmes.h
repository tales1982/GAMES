/*------------------------ ANIMALS ------------------------------*/
#include<stddef.h>
#include<stdio.h>
#include<string.h>
/*----------------------- DECLARATION OF CONSTANTS ---------------------*/
#define EASY 25
#define MEDIUM 20
#define HARD 15

extern void filmes();

void filmes(void)
{
  /*==================== VARIAVEIS ==========================*/
  /*=======================================================*/


  char secret_word[] = "Interstellar";
  int live = 0,option,score = 0,i,tam = 0,compara_string;
  tam = strlen(secret_word);
  char result[tam];
  memset(result,0, sizeof(result));//inizializa meu vetor com 0
  char lettre ;
  int easy = EASY, medium = MEDIUM, hard = HARD; 
  int lista_de_filmes;
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
  /*===================== ESCOLHA DOS ANIMAIS ===============================*/


    // Inicializa o gerador de números aleatórios com uma semente baseada no horário atual
    srand(time(NULL));

    // Gera um número aleatório no intervalo de 1 a 20
    lista_de_filmes = rand() % 20 + 1;

  switch (lista_de_filmes) {
    case 1:
      strcpy(secret_word,"titanic");
      break;
    case 2:
      strcpy(secret_word,"avatar");
      break;
    case 3:
      strcpy(secret_word,"joker");
      break;
    case 4:
      strcpy(secret_word,"gravity");
      break;
    case 5:
      strcpy(secret_word,"interstellar");
      break;
    case 6:
      strcpy(secret_word,"whiplash");
      break;
    case 7:
      strcpy(secret_word,"se7ven");
      break;
    case 8:
      strcpy(secret_word,"aliens");
      break;
    case 9:
      strcpy(secret_word,"predator");
      break;
    case 10:
      strcpy(secret_word,"jumanji");
      break;
    case 11:
      strcpy(secret_word,"armageddon");
      break;
    case 12:
      strcpy(secret_word,"fargo");
      break;
    case 13:
      strcpy(secret_word,"spotlight");
      break;
    case 14:
      strcpy(secret_word,"dunkirk");
      break;
    case 15:
      strcpy(secret_word,"inception");
      break;
    case 16:
      strcpy(secret_word,"psycho");
      break;
    case 17:
      strcpy(secret_word,"blade");
      break;
    case 18:
      strcpy(secret_word,"gladiator");
      break;
    case 19:
      strcpy(secret_word,"rocky");
      break;
    case 20:
      strcpy(secret_word,"scream");
      break;  
  }



  /*========================================================*/
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
      printf("#    Secret word..: %s                   \n",secret_word);
      printf("#    YOU SCORE...: %i                   #\n",score);
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

    live --;
    score -= 5;

  }while (live > -1);

}

