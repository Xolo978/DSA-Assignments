#include <stdio.h>
#define N 4
int board[N][N];

int isSafe(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i][col]) {
      return 0;
    }
  }
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return 0;
    }
  }
  for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
    if (board[i][j]) {
      return 0;
    }
  }
  return 1;
}

void solve(int row) {
  if (row == N) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%d", board[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    return;
  }

  for (int col = 0; col < N; col++) {
    if (isSafe(row, col)) {
      board[row][col] = 1;
      solve(row + 1);
      board[row][col] = 0;
    }
  }
}

int main() { solve(0); }
