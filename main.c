#include "game.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void load_game(char* selected_wrd){
    FILE* words = fopen("wordlist.txt", "r");
    if(!words){
        printf("Could not open file\n");
        exit(0);
    }
    int random_index = rand() % WORD_COUNT;
    //char selected_word[7];
    char buff[8];
    char word_storage[100][7];
    int i = 0;
    while(fgets(buff, sizeof(buff), words)){
        buff[strcspn(buff, "\n")] = '\0';
        strcpy(word_storage[i], buff);
        i++;
    }
    strcpy(selected_wrd, word_storage[random_index]);
    fclose(words);
}

int main()
{
    char selected_word[7];
    char inputted_word[100];
    srand(time(NULL));
    load_game(selected_word);
    //printf("Selected word: %s, len of it: %d\n", selected_word, strlen(selected_word));
    begin_game(selected_word, inputted_word);
    return 0;
}
