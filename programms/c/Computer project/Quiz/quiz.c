#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUESTIONS 100
#define MAX_OPTION 4
#define MAX_OPTION_LENGTH 20
#define MAX_ANSWER_LENGTH 20
#define MAX_QUESTION_LENGTH 100
typedef struct {
  char question[MAX_QUESTION_LENGTH],option[MAX_OPTION][MAX_OPTION_LENGTH];
  int answer;
} quiz;

void takequestion( char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  int i = 0;
  while (fgets(questions[i].question, MAX_QUESTION_LENGTH, file) != NULL &&i < MAX_QUESTIONS) {
     i++;
  } fclose(file);
}
void takeoption( char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  int i = 0;
  while (i < MAX_QUESTIONS && fscanf(file, "%s %s %s %s", questions[i].option[0],questions[i].option[1], questions[i].option[2],questions[i].option[3]) == 4) {
    i++;
  }
  fclose(file);
}
void takeanswer( char *filename, quiz *questions) {
  FILE *file = fopen(filename, "r");
  int i = 0;
  while (fscanf(file, "%d", &questions[i].answer) == 1 && i < MAX_QUESTIONS) {
    i++;
  } fclose(file);
}

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
  }
  printf("Your final score is %d out of %d\n", score, numQuestions);
}
int main() {
  printf("Welcome to Quiz!\nLet's Start, Shall we?:-)\n");
  quiz questions[MAX_QUESTIONS];
  takequestion("questions.txt", questions);   
  takeoption("options.txt", questions);
  takeanswer("answers.txt", questions);
  int numQuestions = 12;  
  conductQuiz(questions, numQuestions); 
  return 0; }
