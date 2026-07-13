
#define WORD_LENGTH 6
#define WORD_COUNT 65
#define WORD_BUFFER_SIZE (WORD_LENGTH + 2)
#define NUM_GUESSES 7
#define YELLOW_BG "\033[43m"
#define GREEN_BG  "\033[42m"
#define GRAY_BG   "\033[100m"
#define BLACK_TEXT "\033[30m"
#define WHITE_TEXT "\033[97m"
#define RESET "\033[0m"

void load_game(char* selected_wrd);
int check_alphanumeric_string(char* str);
int validate_user_input(char* user_inp);
void to_lower_string(char* string);
void to_upper_string(char* string);
void load_user_input(char* user_inp);
int is_letter_in_target(char ch, char* targ);
int is_letter_positioned(char ch, int idx, char* target);
int check_if_correct(int* result_array);
void begin_game(char* target, char* guess);
