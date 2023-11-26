#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num;
char pre;
int max = 5;
int y = 0;
const char *chooseRandomWord(int a) {
  const char *words3[] = {"top", "rat", "bat", "cat", "man", "hat", "hut",
                          "cut", "bit", "pen", "fox", "jog", "zag", "vow",
                          "jug", "joy", "zip", "vox", "jew", "fix", "lux",
                          "zoo", "vex", "gym", "hex", "joy", "pyx", "jib",
                          "wok", "yak", "zap", "box", "coy", "pyx"};
  const char *words4[] = {
      "four", "page", "home", "girl", "bird", "lamp", "drop", "high", "tick",
      "copy", "zeal", "quay", "void", "jazz", "muck", "fizz", "wisp", "jolt",
      "flux", "vast", "cozy", "myth", "viva", "whiz", "gaze", "judo", "quiz",
      "joey", "flaw", "pave", "jinx", "jump", "ramp", "flux", "zinc", "mazy",
      "knee", "jive", "daze", "luxe", "vole", "haze", "buoy", "zest", "whom",
      "fuzz", "zone", "jaws", "lazy", "twig", "quip", "miff", "zany", "dupe",
      "jeep", "whip", "zero", "milk", "jazz", "bump"};
  const char *words5[] = {
      "earth", "nokia", "white", "bread", "table", "zebra", "mango", "paris",
      "eagle", "china", "tiger", "vexed", "quark", "blitz", "jumpy", "woven",
      "glaze", "pyxel", "joust", "vivid", "froze", "buzzy", "hymns", "zilch",
      "fjord", "quiff", "cozyy", "quash", "jowar", "pluck", "mirth", "vouch",
      "pyxel", "mazzy", "lived", "quilt", "myths", "zesty", "dummy", "quips",
      "baked", "jiver", "mosey", "vivid", "quiff", "bumps", "zoned", "lazes",
      "jolly", "wrung", "vexes", "vowel", "joust", "flick", "quash", "pyxel",
      "waxen", "zooms", "pluck", "zilch", "boxed"};

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

void displayWord(const char *word, const char *guessedLetters) {
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

int main() {
  char c;
  credits();
again:
  puts("\n");
  title();
  printf(
      "\n\t\tP:PLAY \n\t\tI:INSTRUCTIONS \n\t\tC:CREDITS \n\t\tQ:QUIT \n\t\t");
  if (num == 4) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
  pre = getchar();
  if (pre == 'q' || pre == 'Q')
    return 0;

  prefrence(pre);
  puts("\n\n");
  page();
  scanf("%d", &num);

  srand(time(NULL));

  if (num == 4) {
    system(CLEAR_SCREEN);
    goto again;
  }
  const char *WordToGuess = chooseRandomWord(num);
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
      printf("Incorrect guesn/ s!\n");
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
  }

  return 0;
}
