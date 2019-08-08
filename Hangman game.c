/*
Hangman game
Pontifícia Universidade Católica de Campinas
Cesar Marrote Manzano
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void printHangman(int vidas);

int main()
{
    //Variables used
    char word[20], wrongLetters[6], rightWord[20], wordLetter;

    int letterAmount, end, confirmation, chances, hits, previousLetter, i;

    do
    {

        chances=6;
        hits=0;
        previousLetter=0;
        end=0;

        printf("Type the desired word: ");
        fflush(stdin);
        gets(word);


        //Tolower -> letters
        for(int i=0; i<strlen(word); i++)
            word[i] = tolower(word[i]);

        //wrongWords -> '-'
        for(int i=0; i<6; i++)
            wrongLetters[i]='-';

        //rightWord -> '-'
        for(int i=0; i<strlen(word); i++)
            rightWord[i]='-';

        system("cls");

        do
        {
            letterAmount=0;


            //Hangman drawn
            printHangman(chances);


            //Show wrongLetters
            printf("\nAlready used letters:");
            for(i=0; i<6; i++)
            {
                printf("%c",wrongLetters[i]);
            }

            //Show rightWord
            printf("\n\nWord Letters:");
            for(i=0; i<strlen(word); i++)
            {
                printf("%c",rightWord[i]);
            }


            //User input -> word letter
            printf("\n\nLetters:");
            fflush(stdin);
            scanf("%c",&wordLetter);
            system("cls");


            //tolower -> letter
            wordLetter = tolower(wordLetter);

            //Checks if the typed letter is in the chosen word
            for(i=0; i<strlen(word); i++)
            {
                if(wordLetter == word[i])
                {
                    rightWord[i]=wordLetter;//The letter is placed at the corresponding '-' position
                    hits++;
                    letterAmount++;
                }
            }

            //Decreasing chances
            if(letterAmount == 0)
            {
                chances --;
                wrongLetters[previousLetter] = wordLetter; //The letter is placed at the corresponding '-' position
                previousLetter++; //The letter will not to be placed in the same position as the previous

                //If the chances end the user loses
                if(chances == 0)
                {
                    printf("YOU LOST!\n\n");
                    system("pause");
                }
                else
                    printf("Wornd letter!%d chances left\n",chances);
            }
            else
                printf("Right letter!\n");

            //Check -> end of the game
            if(hits == strlen(word) || chances == 0)
                end=1;
        }
        while(end!=1);

        system("cls");


        //Show the right word -> end of the game
        if(end == 1 && chances == 0)
        {
            printf("END OF THE GAME!!\n\n");
            printf("The word was:%s\n\n", word);
            system("pause");
        }
        system("cls");


        //Show the right word -> victory
        if(end == 1 && hits == strlen(word))
        {
            printf("YOU WON!!\n\n");
            system("pause");
        }
        system("cls");

        //Play again
        system("cls");
        printf("Try playing again!\n\n");
        printf("Want to play again? <1-Yes> <0-No>");
        scanf("%d",&confirmation);
        system("cls");
    }
    while(confirmation!=0);

    return 0;
}


//printHangmanGame
void printHangman(int chances)
{
    switch (chances)
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
