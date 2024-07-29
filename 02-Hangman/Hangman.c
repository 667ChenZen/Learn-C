#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define WORD_COUNT 50
#define WORD_LENGTH 20

char *my_strchr(char *selected_word, char letter)
{
    int i;

    i = 0;
    while(selected_word[i])
    {
        if (selected_word[i] == letter)
            return &selected_word[i];
        i++;
    }
    return NULL;
}

char my_strncat(char *dest, char *src, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;
    while(n > 0 && src[j])
    {
        dest[i] = src[j];
        dest++;
        src++;
        n--;
    }
    dest[i] = '\0';
}

int my_strlen(char *selected_word)
{
    int i;

    i = 0;
    while (selected_word[i])
        i++;
    return (i);
}

void my_strcpy(char *select_word, char *word_list)
{
    int i = 0;
    while (word_list[i])
    {
        select_word[i] = word_list[i];
        i++;
    }
    select_word[i] = '\0';
}

void select_random_word(char *selected_word)
{
    int randomiser;
    char *word_list[WORD_COUNT] = {
    "chat", "maison", "voiture", "ordinateur", "soleil", "plage", "montagne", "piscine", "boulangerie", "fromage", "cuisine", "jardin", "bibliotheque", "ecole", "universite", "elephant", "giraffe", "hippopotame", "zebre", "panda", "bicyclette", "moto", "avion", "train", "bateau", "requin", "dauphin", "pingouin", "koala", "loutre", "table", "chaise", "canape", "lampe", "rideau", "fenetre", "porte", "armoire", "lit", "oreiller", "parapluie", "valise", "sac", "crayon", "stylo", "livre", "cahier", "carte", "montre", "journal"};
    srand(time(NULL));
    randomiser = rand() % WORD_COUNT;
    my_strcpy(selected_word, word_list[randomiser]);
}

void display_hangman(int remaining_attempts)
{
    switch (remaining_attempts) {
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 0:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
}

void display_game_status(char *word_status, int remaining_attempts, char *guessed_letters)
{
    display_hangman(remaining_attempts);
    printf("Mot a deviner : %s\n", word_status);
    printf("Tentatives restantes : %d\n", remaining_attempts);
    printf("Lettres utilisees : %s\n", guessed_letters);
}

char ask_for_letter()
{
    char letter;
    printf("Entrer une lettre : ");
    scanf(" %c", &letter);
    return (letter);
}

int verify_letter(char letter, char *selected_word, char *word_status, char *guessed_letter)
{
    int i;
    int correct;

    i = 0;
    correct = 0;
    while (selected_word[i])
    {
        if (letter == selected_word[i])
        {
            word_status[i] = letter;
            correct = 1;
        }
        i++;       
    }
    if (my_strchr(selected_word, letter) == NULL)
        my_strncat(guessed_letter, &letter, 1);
    return correct;
}

int has_won(char *word_status)
{
    return (my_strchr(word_status, '_') == NULL);
}

int main(void)
{
    char selected_word[WORD_LENGTH];
    char word_status[WORD_LENGTH];
    int remaining_attempt = MAX_ATTEMPTS;
    char guessed_letter[27] = "";
    int i = 0;
    char letter;

    select_random_word(selected_word);

    while(i < my_strlen(selected_word))
    {
        word_status[i] = '_';
        i++;
    }
    word_status[my_strlen(selected_word)] = '\0';
    
    while (remaining_attempt > 0)
    {
        display_game_status(word_status, remaining_attempt, guessed_letter);

        letter = ask_for_letter();
        if (verify_letter(letter, selected_word, word_status, guessed_letter))
            printf("Bonne lettre !\n");
        else
        {
            remaining_attempt--;
            printf("Mauvaise lettre. Tentatives restantes : %d\n", remaining_attempt);
        }
        if (has_won(word_status)) {
            printf("Felicitations ! Vous avez devine le mot : %s\n", selected_word);
            break;
        }
    }
    if (!has_won(word_status)) {
        display_hangman(0);
        printf("Desole, vous avez perdu. Le mot etait : %s\n", selected_word);
    }
}