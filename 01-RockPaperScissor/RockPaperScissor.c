#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int agrc, char **argv)
{
    char choix;
    char *convertisseur;
    char *choixAdversaire;
    int randomiser;
    srand(time(NULL));
    int mesPoints;
    int pointsAdversaire;
    int again;
    char revenge;

    mesPoints = 0;
    pointsAdversaire = 0;
    revenge = 'y';

    printf("Welcome to Rock-Paper-Scissor !\n");
    printf("\n");

    while(revenge == 'y')
    {
    printf("Enter [s] for scissor, [p] for paper and [r] for rock\n");
    while(scanf(" %c", &choix) && choix != 's' && choix != 'p' && choix != 'r') 
    {
        while (getchar() != '\n');
        printf("Wrong character. Please choose between [s], [p] or [r]\n");
    }

    if (choix == 'r')
        convertisseur = "Rock";
    else if (choix == 'p')
        convertisseur = "Paper";
    else
        convertisseur = "Scissor";
    printf("You choose : %s\n", convertisseur);

    /* 
        1 = rock
        2 = paper
        3 = scissor
    */
    randomiser = 1 + rand() % (3 - 1 + 1);
    if (randomiser == 1)
        choixAdversaire = "Rock";
    else if (randomiser == 2)
        choixAdversaire = "Paper";
    else
        choixAdversaire = "Scissor";
        

    printf("Bot choose = %s\n", choixAdversaire);

    // SCISSOR
    if(choix == 's' && randomiser == 1)
    {
        printf("You loose :/\n");
        pointsAdversaire++;
    }
    else if(choix == 's' && randomiser == 2)
    {
        printf("You win !\n");
        mesPoints++;
    }
    else if(choix == 's' && randomiser == 3)
    {
        printf("Equality ...\n");
    }
    // PAPER
    else if(choix == 'p' && randomiser == 1)
    {
        printf("You win !\n");
        mesPoints++;
    }
    else if(choix == 'p' && randomiser == 2)
    {
        printf("Equality ...\n");
    }
    else if(choix == 'p' && randomiser == 3)
    {
        printf("You loose :/\n");
        pointsAdversaire++;
    }
    // ROCK
    else if(choix == 'r' && randomiser == 1)
    {
        printf("Equality ...\n");
    }
    else if(choix == 'r' && randomiser == 2)
    {
        printf("You loose :/\n");
        pointsAdversaire++;
    }
    else if(choix == 'r' && randomiser == 3)
    {
        printf("You win !\n");
        mesPoints++;
    }

    printf("Score %d - %d\n", mesPoints, pointsAdversaire);

    printf("Revenge ? Say [y] for yes OR [n] for no.\n");
    while(scanf(" %c", &revenge) && revenge != 'y' && revenge != 'n')
    {
        while (getchar() != '\n');
        printf("Wrong character. Please choose between [y] for continue or [n] for stop\n");
    }
    if (revenge == 'n')
    {
        printf("\n");
        if(mesPoints > pointsAdversaire)
            printf("The winner is you ! Congrats.\n");
        else if(mesPoints < pointsAdversaire)
            printf("The winner is the bot ! You'll do better next time.\n");
        else
            printf("Equality ! There is no winner.\n");
        return 0;
    }
    }
}