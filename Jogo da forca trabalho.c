/*
Jogo da forca 1ºsemestre - PUCC
Cesar Marrote Manzano
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void imprime_forca(int vidas);

int main()
{

    char palavras_possiveis[10][20]= {"Engenheiro","Professor","Carteiro","Agroecologo",
                                      "Motorista","Bioinformacionista","Medico","Enfermeiro","Cientista","Arquiteto"
                                     };

    char palavra[20], letra_da_palavra;

    char vetor_erros[6], vetor_acertos[20];

    int letra_quantidade, termino, confirmacao, tamanho_palavra, k;

    int chances, acertos, verificaLetra;

    do
    {

        chances=6;
        acertos=0;
        k=0;
        termino=0;

        printf("Sugestoes de palavras:\n\n");
        for(int i=0; i<10; i++)
        {
            puts(palavras_possiveis[i]);
        }
        printf("\n");
        printf("Digite a palavra desejada:");
        fflush(stdin);
        gets(palavra);
        tamanho_palavra = strlen(palavra);

        //Todas as letras da palavra sao convertidas para letras minúsculas
        for(int i=0; i<tamanho_palavra; i++)
            palavra[i] = tolower(palavra[i]);

        //Coloca '-' em todas as posições do vetor_erros
        for(int i=0; i<6; i++)
            vetor_erros[i]='-';

        //Coloca '-' em todas as posições do vetor_acertos
        for(int i=0; i<tamanho_palavra; i++)
            vetor_acertos[i]='-';

        system("cls");

        do
        {
            letra_quantidade=0;


            //Desenho da forca
            imprime_forca(chances);

            //Mostra o vetor_erros
            printf("\nLetras ja usadas:");
            for(int i=0; i<6; i++)
            {
                printf("%c",vetor_erros[i]);
            }

            //Mostra o vetor_acertos
            printf("\n\nLetras da palavra:");
            for(int i=0; i<tamanho_palavra; i++)
            {
                printf("%c",vetor_acertos[i]);
            }


            //Usuário digita letra da palavra
            printf("\n\nLetra:");
            fflush(stdin);
            scanf("%c",&letra_da_palavra);
            system("cls");


            //Converte a letra digtada em minuscula
            letra_da_palavra = tolower(letra_da_palavra);

            //Verifica se a letra digitada está na palavra escolhida
            for(int i=0; i<tamanho_palavra; i++)
            {
                if(letra_da_palavra == palavra[i])
                {
                    vetor_acertos[i]=letra_da_palavra;//A letra é colocada na posição do '-' correspondente
                    acertos++;
                    letra_quantidade++;
                }
            }

            //Diminui suas chances se a letra digitada não está na palavra
            if(letra_quantidade == 0)
            {
                chances --;
                vetor_erros[k]=letra_da_palavra;//A letra é colocada na posição do '-'
                k++; //Serve para a letra não ser colocada na mesma posição da anterior

                //Se as chances acabarem o usuário perde
                if(chances==0)
                {
                    printf("VOCE PERDEU!\n\n");
                    system("pause");
                }
                else
                    printf("Letra errada!Restam %d chances\n",chances);
            }
            else
                printf("Voce acertou uma letra!\n");

            //Verificação para terminar o jogo
            if(acertos == tamanho_palavra||chances == 0)
                termino=1;
        }
        while(termino!=1);

        system("cls");

        //Mostra a palavra correta se o jogador perdeu e quiser jogar novamente
        if(termino==1 && chances==0)
        {
            printf("FIM DE JOGO!!\n\n");
            printf("A palavra era:%s\n\n", palavra);
            system("pause");
        }
        system("cls");

        //Caso o jogador tenha acertado a palavra
        if(termino==1 && acertos==tamanho_palavra)
        {
            printf("Parabens voce ganhou!!\n\n");
            system("pause");
        }
        system("cls");

        //Verificação para jogar novamente
        system("cls");
        printf("Tente jogar mais uma vez!\n\n");
        printf("Deseja jogar novamente?<1-Sim><0-Nao>");
        scanf("%d",&confirmacao);
        system("cls");
    }
    while(confirmacao!=0);

    return 0;
}


//Função de impressão da forca
void imprime_forca(int vidas)
{
    switch (vidas)
    {
    case 6:
        printf(" _________\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 5:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 4:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 3:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 2:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 1:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|        / \n");
        printf("|       / \n");
        printf("|\n");
        printf("|_______\n");
        break;

    case 0:
        printf(" _________\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|        / \\\n");
        printf("|       /   \\\n");
        printf("|\n");
        printf("|_______\n\n");
        break;
    }
}
