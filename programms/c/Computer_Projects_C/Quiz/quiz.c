#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>////to manipulate the terminal output dela
//macro to define the maximum no. of each parameters
#define MAX_QUESTIONS 100
#define MAX_OPTION 4
#define MAX_OPTION_LENGTH 20
#define MAX_ANSWER_LENGTH 20
#define MAX_QUESTION_LENGTH 100
//check if the OS is windows or other 
#ifdef _WIN32
  #define CLEAR_SCREEN "cls"
#else
  #define CLEAR_SCREEN "clear"
#endif

//Structure to save the questions, options and answers generated 
typedef struct {
  char question[MAX_QUESTION_LENGTH],option[MAX_OPTION][MAX_OPTION_LENGTH];
  int answer;
} quiz;
//Declare the functions needed &&pointer *questions is not the same as char questions in the structure and is just the pointer to check around the structure 
//take questions from the file "questions.txt" as initialized in main()
void takequestion(const char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error Opening File");
    exit(EXIT_FAILURE);
  }
  int i = 0;
  while (fgets(questions[i].question, MAX_QUESTION_LENGTH, file) != NULL &&i < MAX_QUESTIONS) {
    questions[i].question[strcspn(questions[i].question, "\n")] = '\0'; i++;
  } fclose(file);
}
//take questions from the file "options.txt" as initialized in main()
void takeoption(const char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error Opening File");
    exit(EXIT_FAILURE);
  }
  int i = 0;
  while (i < MAX_QUESTIONS &&
         fscanf(file, "%s %s %s %s", questions[i].option[0],questions[i].option[1], questions[i].option[2],questions[i].option[3]) == 4) {
    i++;
  }

  fclose(file);
}
//take answers from the file "answers.txt" as initialized in main()
void takeanswer(const char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error Opening File");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while (fscanf(file, "%d", &questions[i].answer) == 1 && i < MAX_QUESTIONS) {
    i++;
  } fclose(file);
}

//display questions, options .. take and check the answers 
void conductQuiz(quiz *questions, int numQuestions) {
  int score = 0;

  for (int i = 0; i < numQuestions; i++) {
    printf("Question %d: %s\n", i + 1, questions[i].question);

    for (int j = 0; j < MAX_OPTION; j++) {
      printf("%d. %s\n", j + 1, questions[i].option[j]);
    }
    int userAnswer;
    printf("Your answer (1-4): ");
    scanf("%d", &userAnswer);
    if (userAnswer == questions[i].answer) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %d\n", questions[i].answer);
    }
    printf("\n");
  }
  printf("Your final score is %d out of %d\n", score, numQuestions);
}
void credits(void) {//roll up the credits in startup
  system(CLEAR_SCREEN);
  printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPROJECT\n\t\t\t\tQuiz"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tMADE BY\n\t\t\t     Charchil Neupane"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tROLL NO\n\t\t\t\t      12"); sleep(2);
  printf("\n\n\n\n\t\t\t\tSECTION\n\t\t\t          M11"); sleep(2);
  printf("\n\n\n\n\t\t\t\tINSTITUTE:Kathmandu Model Secondary School"); sleep(2);
  printf("\n\n\n\n\n\t\t\t\tSUBMITTED TO:Computer Department\n\t\t\t"); sleep(2);
  system(CLEAR_SCREEN);}

int main() {
  credits();
  printf("Welcome to Quiz!\nLet's Start, Shall we?:-)\n");
  quiz questions[MAX_QUESTIONS];
  takequestion("questions.txt", questions);    //function call to store each of the parameters in the structure
  takeoption("options.txt", questions);
  takeanswer("answers.txt", questions);
  int numQuestions = 12;  //initialize the max amount of questions 
  conductQuiz(questions, numQuestions); //function call to display the acutal content 
  return 0; }
