#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>////to manipulate the terminal output delay
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

//function declaration 
int prefrence(char);
void show(int, int);
void page(void);
void title(void);
void inst(void);
void hangman(int, int);
void credits(void);
//Display title at startup 
inline void title(void) {
  printf("--------------------------------------------\n");
  printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
  printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
  printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
  printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
  printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
  printf("--------------------------------------------\n\n"); }

//instruction to be displayed 
inline void inst(void) {
  system(CLEAR_SCREEN);
  printf("\n\n\n\t\t INSTRUCTIONS \n\t\t ============\n");
  printf("\n   1: HANGMAN IS A GAME WHERE YOU HAVE TO GUESS THE WORD.");
  printf("\n   2: GUESS THE MAXIMUM WORDS FOR THE MAXIMUM SCORE.");
  printf("\n   3: EVERY LEVEL WILL HAVE A NEW WORD.");
  printf("\n   4: 1 CORRECT LETTER = 1 SCORE");
  printf("\n   5: YOU HAVE LIMITED CHANCES TO FIND THE WORD\n\n\n"); sleep(6); 
  system(CLEAR_SCREEN);
  printf("\n\n\n\n\t\t   HOW TO PLAY \n\t\t ===========");
  printf("\nUse your keyboard to guess the word. If you press any letter and the letter is in the word, the game will tell you the position of the letter.\nGuess more, score more.\n\n\t\t\t BEST OF LUCK !");
}
//displays the credits in startup of the program
inline void credits(void) {
  system(CLEAR_SCREEN);
  printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPROJECT\n\t\t\t     HANGMAN ON C"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tMADE BY\n\t\t\t     Charchil Neupane"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tROLL NO\n\t\t\t\t      12");sleep(2);
  printf("\n\n\n\n\t\t\t\tSECTION\n\t\t\t          M11"); sleep(2);
  printf("\n\n\n\n\t\t\t\tINSTITUTE:Kathmandu Model Secondary School"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tSUBMITTED TO:Computer Department\n\t\t\t");  sleep(2);
  system(CLEAR_SCREEN);
}
//The inner page where the player can select the difficulty levels 
inline void page(void) {
  printf("\t\t\t  \n");
  printf("\t\t\t      \n");
  printf("\t\t\t      0 \n");
  printf("\t\t\t     \\|/\n");
  printf("\t\t\t      | \n");
  printf("\t\t\t     / \\\n");
  printf("\t         CAN YOU SAVE ME PLESASE ?  \n\n");
  printf("\n\t\t 1: 3 LETTERS GAME (Beginner) \n\t\t 2: 4 LETTERS GAME (ok i ""guess..) \n\t\t 3: 5 LETTERS GAME (ngl it's pretty hard) \n\n\t\t ""\n\n\t\t 4:MAIN MENU \n\n\t\t choice = ");
}
//the function that prints the ascii art of the hangman according to parameters score entered
inline void show(int a, int score) {
  switch (a) {
  case 1:
  {
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    printf("\nYour score = %d", score);
    printf("\n\t\t\t\t Chances Left=%d", 5 - a);
  } break;

  case 2:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    printf("\nYour score = %d", score);
    printf("\n\t\t\t\t Chances Left=%d", 5 - a);

    break;

  case 3:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("  |    |\n");
    printf("  |    |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    printf("\nYour score = %d", score);
    break;

  case 4:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("  |   \\|/\n");
    printf("  |    | \n");
    printf("  |   /\n");
    printf("__|_________\n\n");
    printf("\nYour score = %d", score);
    printf("\n\t\t\t\t Chances Left=%d", 5 - a);

    break;

  case 5:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    X \n");
    printf("  |   \\|/\n");
    printf("  |    | \n");
    printf("  |   / \\\n");
    printf("__|_________\n\n");
    printf("\nTotal score = %d", score);
    printf("\n\t\t\t\t Chances Left=%d", 5 - a);
    printf("\n\nYOU ARE DEAD ! GAME OVER!");

    break;
  }
}
//Scan and display the inner page of the program according to user choices 
inline int prefrence(char a) {
  switch (a) {
  case 'p':
  case 'P':
    system(CLEAR_SCREEN);
    break;

  case 'i':
  case 'I':
    inst();
    break;

  case 'c':
  case 'C':
    credits();
    break;

  default:
    printf("Invalid Input! Try Again.");
  }
  return 0;
}
