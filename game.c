#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int check_alphanumeric_string(char* str){
    for(int i =0; i< (int)strlen(str); i++ ){
        if(!isalpha((unsigned char)str[i])){
            return 0;
        }
    }
    return 1;
}

int validate_user_input(char* user_inp){
    if(strlen(user_inp) != 6){
        printf("You must enter a six letter word\n");
        return 0;
    }else if(!check_alphanumeric_string(user_inp)){
        printf("You must enter only letters\n");
        return 0;
    }else{
        return 1;
    }
}

void to_lower_string(char* string){
    for(int i = 0; i < (int)strlen(string); i++){
        string[i] = tolower(string[i]);
    }
}

void to_upper_string(char* string){
    for(int i = 0; i < (int)strlen(string); i++){
        string[i] = toupper(string[i]);
    }
}

void load_user_input(char* user_inp){
    char user_input[100];
    int passed = 0;
    while(passed == 0){
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0'; 
        to_lower_string(user_input);
        passed = validate_user_input(user_input);
    }
    strcpy(user_inp, user_input);
}

int is_letter_in_target(char ch, char* targ){
    char* result = strchr(targ, ch);
    if(!result){
        return 0;
    }else{
        return 1;
    }
}

int is_letter_positioned(char ch, int idx, char* target){
    if(target[idx] == ch){
        return 1;
    }else{
        return 0;
    }
}

int check_if_correct(int* result_array){
    int found_false = 0;
    for(int i = 0; i < 6; i++){
        if(result_array[i] != 2){
            found_false = 1;
        }
    }
    return !found_false;
}

void initialize_result_arry(int* res_ary){
    for(int i = 0; i < 6; i++){
        res_ary[i] = 0;
    }
}

int find_idx_of_found_letter(char lett, char* target){
    for(int k = 0; k < (int)strlen(target); k++){
        if(target[k] == lett){
            return k;
        }
    }
    return -1;

}

void initialize_str(char* strng){
    for(int i = 0; i < WORD_LENGTH+1; i++){
        strng[i] = '_';
    }
}

void begin_game(char* target, char* guess){
    int is_correct = 0;
    int k = 0;
    int idx_of_found_letter;
    char found_letts[7];
    initialize_str(found_letts);

    for(k = 0; k < NUM_GUESSES && is_correct == 0; k++){
        int result_arry[6];
        initialize_result_arry(result_arry);
        char rem_letts[7];
        strcpy(rem_letts,target);
        printf("Enter a six letter word - Guess #%d\n", k+1);
        load_user_input(guess);
        
        for(int i = 0; i < (int)strlen(guess); i++){ 
            if(is_letter_positioned(guess[i], i, target)){
                result_arry[i] = 2;
                rem_letts[i] = '*';
                found_letts[i] = guess[i];
            }
        }

        for(int i = 0; i < (int)strlen(guess); i++){
            if(is_letter_in_target(guess[i], rem_letts) && result_arry[i] == 0){
                result_arry[i] = 1;
                idx_of_found_letter = find_idx_of_found_letter(guess[i], target);
                rem_letts[idx_of_found_letter] = '*';
                found_letts[i] = guess[i];
            }
        }
        // printf("Your guess:                    %c %c %c %c %c %c\n",guess[0], guess[1], guess[2], guess[3], guess[4], guess[5]);
        // printf("Results:                       %d %d %d %d %d %d\n",result_arry[0], result_arry[1], result_arry[2], result_arry[3], result_arry[4], result_arry[5] );
        for(int i = 0; i < WORD_LENGTH; i++){
            if(result_arry[i] == 2){
                printf("%s%s %c %s ", GREEN_BG, BLACK_TEXT, guess[i], RESET);
            }else if(result_arry[i] == 1){
                printf("%s%s %c %s ", YELLOW_BG, BLACK_TEXT, guess[i], RESET);
            }else{
                printf("%s%s %c %s ", GRAY_BG, WHITE_TEXT, guess[i], RESET);
            }
        }

        printf("\n");

        if(check_if_correct(result_arry)){
            is_correct = 1;
            break;
        }
    }

    if(is_correct){
        to_upper_string(target);
        printf("Congrats! You guessed the word %s in %d guesses\n", target, k+1);
    }else{
        to_upper_string(target);
        printf("You lost - the word was %s\n", target);
    }
}
