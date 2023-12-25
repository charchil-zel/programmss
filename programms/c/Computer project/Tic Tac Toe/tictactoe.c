#include <stdio.h>
#include <stdlib.h>
char board[3][3], PLAYER_X = 'X', PLAYER_O = 'O';
void resetBoard() {

 for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}
void printBoard() {
  printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
  printf("\n\n");
}

int freeSpaceCheck() {
  int freeSpaces = 9;
  for (int i = 0, j = 0; i < 3 && j < 3; i++, j++) {
    if (board[i][j] != ' ') {
      freeSpaces--;
    }
  }
  return freeSpaces;
}
void playerMove(char currentPlayer) {
  int x, y;
  printf("Player %c, enter row #(1-3): ", currentPlayer);
  scanf("%d", &x);
  x--;
  printf("Player %c, enter column #(1-3): ", currentPlayer);
  scanf("%d", &y);
  y--;  
  do {
    if (board[x][y] != ' ') {
      printf("Invalid move, try again.\n");
      printBoard();
      playerMove(currentPlayer);
    } else {
      board[x][y] = currentPlayer;
      break;
    }
  } while (board[x][y] == ' ');
}
char checkWinner() {
  for (int i = 0; i < 3; i++) {
   if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' '; }
void printWinner(char winner) {
  if (winner == PLAYER_X) {
    printf("Player X Wins!\n");
  } else if (winner == PLAYER_O) {
    printf("Player O Wins!\n");
  } else {
    printf("It's a tie!\n");
  }
}

void friends()
{
   char response, winner=' '; 
  do {
    char winner = ' ';
    char response = ' ';
    resetBoard();
    while (winner == ' ' && freeSpaceCheck() != 0) {
      printBoard();
      playerMove(PLAYER_X);
      winner = checkWinner();
      if (winner != ' ' || freeSpaceCheck() == 0) {
        break;
      }
      printBoard();
      playerMove(PLAYER_O);
      winner = checkWinner();
      if (winner != ' ' || freeSpaceCheck() == 0) {
        break;
      }
    }
    printBoard();
    printWinner(winner);
    printf("\nDo you want to play again? (Y/N)\n");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
      system("cls");
    }
  } while (response == 'Y' || response == 'y');
}
int main() {
  friends();
  return 0;
}
