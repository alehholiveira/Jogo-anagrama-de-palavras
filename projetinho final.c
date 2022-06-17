#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define TAM 30


void cabecalho (int contaA, int contaE, char respostascertas[][20]) {
    system("cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t\tJOGO ANAGRAMA\n");
    printf("\tREGRAS:");
    printf("\n\t > forme palavras com as letras do quadro");
    printf("\n\t > total de 30 palavras");
    printf("\n\t > com 5 erros o jogo acaba\n\n");
    printf("\t B O A   S O R T E !\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t QUADRO DE LETRAS\n\t");
    letras_disponiveis();
    printf("\n\n");
    printf("\n>>> ACERTOS (%d de 30) e Erros (%d de 5):\n", contaA, contaE);
    if (contaA>0){
        printf("\nPALAVRAS DOS ACERTOS: ");
        for (int i = 0; i < contaA; i++){
            printf("%s  ", respostascertas[i+1]);
        }
    }
}

void letras_disponiveis(){
    char letras []= {'P','A','R','B','F','I','D','E','C','Q','R','M','V','L','T','N','J','S','A','O','U','D','G','R'};
    printf(" ________________\n\t");
    printf("|\t\t | \n");
    printf("\t| ");
    for (int i = 0; i < 5; i++)
        printf("%c  ", letras[i]);
        printf("|");
        printf("\n\t");
        printf("| ");
    for (int i = 5; i < 10; i++)
        printf("%c  ", letras[i]);
        printf("|");
        printf("\n\t");
        printf("| ");
    for (int i = 10; i < 15; i++)
        printf("%c  ", letras[i]);
        printf("|");
        printf("\n\t");
        printf("| ");
    for (int i = 15; i < 20; i++)
        printf("%c  ", letras[i]);
        printf("|");
        printf("\n\t");
        printf("| ");
    for (int i = 20; i < 24; i++)
        printf("%c  ", letras[i]);
        printf("\t |");
        printf("\n\t|________________|");
}

void ler_string(char respostas[]){
    printf("\n\nPara encerrar - digite 'exit'");
    printf("\n>> ");
    fflush(stdin); scanf("%[^\n]", respostas);
}

void validar_palavras(char respostas[]){
    int flag;
    do {
        flag = 1;
        ler_string(respostas);
        strlwr(respostas);
        for(int i=0;i<strlen(respostas);i++){
            if (!isalpha(respostas[i])){
                flag = 0;
                printf ("Nao eh valido numeros e acentos! Digite novamente: ");
                break;
            }
        }
    }while (flag == 0);
}

void verificar_banco_de_dados(char respostas[], int *contaA, int *contaE, char respostascertas[][20], char bancopalavra[][20]){
    int testar=0;
    for (int i = 0; i < 31; i++){
        if(strcmp(respostas,respostascertas[i]) == 0)
            do{
                printf("\nPALAVRA JA CONSTA NO BANCO DE ACERTOS, DIGITE NOVAMENTE!!");
                validar_palavras(respostas);
        }while (strcmp(respostas,respostascertas[i]) == 0);
    }
    for (int i = 0; i < 31; i++){
        if(strcmp(respostas,bancopalavra[i]) == 0){
            (*contaA)++;
            strcpy(respostascertas[*contaA], respostas);
            testar++;
        }
    testar++;
    }
    if (strcmp(respostas, "exit") == 0){
        encerrar_jogo(bancopalavra);
    }

    if(testar == 31)
        (*contaE)++;
}

void encerrar_jogo(char bancopalavra[][20]){
    int escolha; system("cls");
    printf("\n\n>> Deseja ver o banco de palavras?\n[1] para visualizar o banco de palavras;\n[2] encerrar o jogo;\n>  "); scanf("%d", &escolha); printf("\n\t");
    switch(escolha){
    case 1:      system("cls"); printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\t\t<< BANCO DE PALAVRAS >>"); printf("\n\n");
                 for (int i = 0; i < 9; i++)
                    printf("%s   ", bancopalavra[i]);
                    printf("\n");
                 for (int i = 9; i < 17; i++)
                    printf("%s   ", bancopalavra[i]);
                    printf("\n");
                 for (int i = 17; i < 25; i++)
                    printf("%s   ", bancopalavra[i]);
                    printf("\n");
                 for (int i = 25; i < 30; i++)
                    printf("%s   ", bancopalavra[i]);

                 printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
                 printf("\n\n<< OBRIGADO POR JOGAR! >>\n\n\n");
                 system("pause");
                 exit (0);
                 break;

    case 2:      printf("\n<< OBRIGADO POR JOGAR! >>\n\n\n");
                 system("pause");
                 exit (0);
                 break;

    default: printf("\n\n\n");
    }
}

void parabens(int contaA, char respostascertas[][20]){
    if (contaA == 30){
            system("color A"); system("cls");
            printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-  PARABENS  -=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("\n\t>> Obrigado por concluir o jogo do anagrama. Esperamos que tenha sido um bom desafio.\n\n\t");
                     for (int i = 1; i < 9; i++)
                        printf("%s   ", respostascertas[i]);
                        printf("\n\t");
                     for (int i = 9; i < 17; i++)
                        printf("%s   ", respostascertas[i]);
                        printf("\n\t");
                     for (int i = 17; i < 25; i++)
                        printf("%s   ", respostascertas[i]);
                        printf("\n\t");
                     for (int i = 25; i < 31; i++)
                        printf("%s   ", respostascertas[i]);
            printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\n\n");
            system("pause");
    }
}

void perdeu(int contaE, char bancopalavra[][20]){
    if (contaE == 5){
        printf("\n\n>> VOCE PERDEU!! \n\n");
        system("pause");
        encerrar_jogo(bancopalavra);
    }
}

int main () {

    setlocale(LC_ALL,""); system("cls"); system("color D");
    char BANCOPALAVRA[TAM][20]={"pedra","roupa","cola","sapato","prima","faculdade","rato","gato","caro",
                               "jacare","festival","andar","pular","correr","saltar","casual","competir",
                               "loja","novidade","categoria","gol","turno","tabua","dama","roda","pneu",
                               "brasil","copa","mundo","subir"};
    char RESPOSTAS[20];
    char RESPOSTASCERTAS[TAM][20];
    int contacertos = 0, contaerros = 0;

    while (contacertos < 30 && contaerros < 5){
        cabecalho(contacertos, contaerros, RESPOSTASCERTAS);
        validar_palavras(RESPOSTAS);
        verificar_banco_de_dados(RESPOSTAS, &contacertos, &contaerros, RESPOSTASCERTAS, BANCOPALAVRA);
    }

    cabecalho(contacertos, contaerros, RESPOSTASCERTAS);
    parabens(contacertos, RESPOSTASCERTAS);
    perdeu(contaerros, BANCOPALAVRA);

    return 0;
}

