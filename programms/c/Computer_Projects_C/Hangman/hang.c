#include "fun.h"
int num,max = 5,y = 0;
char pre;
//Function to select the word according to random index generated and return it 
const char *chooseRandomWord(int a) {
  const char *words3[] = {"top", "rat", "bat", "cat", "man", "hat", "hut","cut", "bit", "pen", "fox", "jog", "zag", "vow","jug", "joy", "zip", "vox", "jew", "fix", "lux","zoo", "vex", "gym", "hex", "joy", "pyx", "jib","wok", "yak", "zap", "box", "coy", "pyx"};
  const char *words4[] = {"four", "page", "home", "girl", "bird", "lamp", "drop", "high", "tick","copy", "zeal", "quay", "void", "jazz", "muck", "fizz", "wisp", "jolt","flux", "vast", "cozy", "myth", "viva", "whiz", "gaze", "judo", "quiz","joey", "flaw", "pave", "jinx", "jump", "ramp", "flux", "zinc", "mazy","knee", "jive", "daze", "luxe", "vole", "haze", "buoy", "zest", "whom","fuzz", "zone", "jaws", "lazy", "twig", "quip", "miff", "zany", "dupe","jeep", "whip", "zero", "milk", "jazz", "bump"};
  const char *words5[] = {"earth", "nokia", "white", "bread", "table", "zebra", "mango", "paris","eagle", "china", "tiger", "vexed", "quark", "blitz", "jumpy", "woven","glaze", "pyxel", "joust", "vivid", "froze", "buzzy", "hymns", "zilch","fjord", "quiff", "cozyy", "quash", "jowar", "pluck", "mirth", "vouch","pyxel", "mazzy", "lived", "quilt", "myths", "zesty", "dummy", "quips","baked", "jiver", "mosey", "vivid", "quiff", "bumps", "zoned", "lazes","jolly", "wrung", "vexes", "vowel", "joust", "flick", "quash", "pyxel","waxen", "zooms", "pluck", "zilch", "boxed"};
  if (a == 1) {//'a' checks the number of character user wants to play with 
    int index = rand() % (sizeof(words3) / sizeof(words3[0])); //generate random index withe the limits from 0 to no. of words declared
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
//displays the words by comparing the each character entered by user 
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
again:  puts("\n");
  title();
  printf("\n\t\tP:PLAY \n\t\tI:INSTRUCTIONS \n\t\tC:CREDITS \n\t\tQ:QUIT \n\t\t");
  if (num == 4) {
    while ((c = getchar()) != '\n' && c != EOF);
  }
  pre = getchar();
  if (pre == 'q' || pre == 'Q')
    return 0; 
  prefrence(pre);
  puts("\n\n");
  page();
  scanf("%d", &num);
  srand(time(NULL)); //Provide a seed for the use of rand() function above 
  if (num == 4) {
    system(CLEAR_SCREEN);
    goto again;
  }
  const char *WordToGuess = chooseRandomWord(num);  //initialize pointer char to pass into the choooseRandomWord() 
  int wordLength = strlen(WordToGuess);
  char guessedLetters[wordLength];
  int incorrectGuesses = 0;
  for (int i = 0; i < wordLength; i++) {
    guessedLetters[i] = '_';// intially generate the lower border for word
  }
  while (1) {
    printf("\n");
    displayWord(WordToGuess, guessedLetters);
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess); //clear stream
    if (strchr(WordToGuess, guess) != NULL) {//compare the character entered and to be enter 
      printf("Correct guess!\n");
      y++;
      for (int i = 0; i < wordLength; i++) {//if correct letter is guessed 
        if (WordToGuess[i] == guess) {
          guessedLetters[i] = guess;
        }
      }
    } else {
      printf("Incorrect guesn/ s!\n");
      incorrectGuesses++;
      max -= 1;//reduce the max tries remaining 
      show(incorrectGuesses, y);
      if (max == 0) {                                             // if the max guess reached
        printf("\nThe correct word was: %s\n", WordToGuess);
        break;
      }
    }
    if (strcmp(WordToGuess, guessedLetters) == 0) {
      printf("Congratulations! You guessed the word: %s\n", WordToGuess);// if the whole word was guessed 
      break;
      return 0;
    }
  }  return 0; }
