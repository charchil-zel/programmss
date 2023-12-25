#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int num,max = 5,y = 0;
char pre;
 char *chooseRandomWord(int a) {
   char *words3[] = {"top", "rat", "bat", "cat", "man", "hat", "hut","cut", "bit", "pen", "fox", "jog", "zag", "vow","jug", "joy", "zip", "vox", "jew", "fix", "lux","zoo", "vex", "gym", "hex", "joy", "pyx", "jib","wok", "yak", "zap", "box", "coy", "pyx"};
   char *words4[] = {"four", "page", "home", "girl", "bird", "lamp", "drop", "high", "tick","copy", "zeal", "quay", "void", "jazz", "muck", "fizz", "wisp", "jolt","flux", "vast", "cozy", "myth", "viva", "whiz", "gaze", "judo", "quiz","joey", "flaw", "pave", "jinx", "jump", "ramp", "flux", "zinc", "mazy","knee", "jive", "daze", "luxe", "vole", "haze", "buoy", "zest", "whom","fuzz", "zone", "jaws", "lazy", "twig", "quip", "miff", "zany", "dupe","jeep", "whip", "zero", "milk", "jazz", "bump"};
   char *words5[] = {"earth", "nokia", "white", "bread", "table", "zebra", "mango", "paris","eagle", "china", "tiger", "vexed", "quark", "blitz", "jumpy", "woven","glaze", "pyxel", "joust", "vivid", "froze", "buzzy", "hymns", "zilch","fjord", "quiff", "cozyy", "quash", "jowar", "pluck", "mirth", "vouch","pyxel", "mazzy", "lived", "quilt", "myths", "zesty", "dummy", "quips","baked", "jiver", "mosey", "vivid", "quiff", "bumps", "zoned", "lazes","jolly", "wrung", "vexes", "vowel", "joust", "flick", "quash", "pyxel","waxen", "zooms", "pluck", "zilch", "boxed"};
  if (a == 1) {
    int index = rand() % (sizeof(words3) / sizeof(words3[0])); 
    return words3[index];
  }
  if (a == 2) {
    int index = rand() % (sizeof(words3) / sizeof(words3[0]));
    return words4[index];
  }
  if (a == 3) {
    int index = rand() % (sizeof(words3) / sizeof(words3[0]));
    return words5[index];
  }
  return NULL;
}
void displayWord( char *word,  char *guessedLetters) {
  for (int i = 0; word[i] != '\0'; i++) {
    if (strchr(guessedLetters, word[i]) != NULL) {
      printf("%c", word[i]);
    }
    else {
      printf("_ ");
    }
  }
  printf("\n");
}

void show(int a, int score) {
  switch (a) {
  case 1:
  {
    printf("  _______\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("\nwrong letters: %d\n\n score = %d Chances Left=%d",a,score ,5 - a);

  } break;

  case 2:
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("\nwrong letters: %d\n\n score = %d Chances Left=%d",a,score ,5 - a);
    

    break;

  case 3:
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("  |    |\n");
    printf("\nwrong letters: %d\n\n score = %d Chances Left=%d",a,score ,5 - a);
    break;

  case 4:
    printf("  _______\n");
    printf("  |/   | \n");
   printf(" | O \n| \\|/\n| | \n| /\n");
    printf("\nwrong letters: %d\n\n score = %d Chances Left=%d",a,score ,5 - a);
    break;

  case 5:
    printf("  _______\n");
    printf("  |/   | \n|    X \n|   \\|/\n|    | \n|   / \\\n");
    printf("\nwrong letters: %d\n\n score = %d Chances Left=%d",a,score ,5 - a);
    break;
  }
} 

int main() {
  char c;
again:  puts("\n");
  printf("\nP:PLAY \nQ:QUIT\n");
  
  pre = getchar();
  if (pre == 'q' || pre == 'Q')
    return 0; 
  srand(time(NULL)); 
  system("cls");
  printf("\n 1: 3 LETTERS GAME (Beginner) \n 2: 4 LETTERS GAME (ok i ""guess..) \n 3: 5 LETTERS GAME (ngl it's pretty hard) \n""\n 4:MAIN MENU \nchoice = ");
int num;
scanf("%d",&num);

  char *WordToGuess = chooseRandomWord(num);  
  int wordLength = strlen(WordToGuess);
  char guessedLetters[wordLength];
  int incorrectGuesses = 0;
  for (int i = 0; i < wordLength; i++) {
    guessedLetters[i] = '_';
  }
  while (1) {
    printf("\n");
    displayWord(WordToGuess, guessedLetters);
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess); 
    if (strchr(WordToGuess, guess) != NULL) { 
      printf("Correct guess!\n");
      y++;
      for (int i = 0; i < wordLength; i++) {
        if (WordToGuess[i] == guess) {
          guessedLetters[i] = guess;
        }
      }
    } else {
      printf("Incorrect guess!\n");
      incorrectGuesses++;
      max -= 1; 
      show(incorrectGuesses, y);
      if (max == 0) {                                             
      printf("\nThe correct word was: %s\n", WordToGuess);
      break;
    }
    }
    if (strcmp(WordToGuess, guessedLetters) == 0) {
      printf("Congratulations! You guessed the word: %s\n", WordToGuess);
      break;
      return 0;
    }
  }  return 0; }
