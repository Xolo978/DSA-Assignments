#include <stdio.h>
int main() {
  int input[] = {3, 2, 7, 5};
  int n = 4, target = 8;
  int dp[n + 1][target + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (j == 0) {
        dp[i][j] = 1;
        continue;
      } else if (i == 0) {
        dp[i][j] = 0;
        continue;
      }
      int leave = dp[i - 1][j];
      if (input[i - 1] > j) {
        dp[i][j] = leave;
      } else {
        int take = dp[i - 1][j - input[i - 1]];
        dp[i][j] = leave || take;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  int i = n, j = target;

  printf("Subset: ");
  while (i > 0 && j > 0) {
    // Leave
    if (dp[i - 1][j]) {
      i--;
    } else {
      // Take it
      printf("%d,", input[i - 1]);
      j -= input[i - 1];
      i--;
    }
  }
  printf("\n");
}
