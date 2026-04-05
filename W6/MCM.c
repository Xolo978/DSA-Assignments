#define N 100
int dp[N][N];
int solve(int p[], int i, int j) {
  if (i >= j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int min = -1000000;
  for (int k = i; k < j; k++) {
    int cost = solve(p, i, k) + solve(p, k + 1, j) + p[i - 1] * p[k] * p[j];
    if (cost < min) {
      min = cost;
    }
  }
  return min;
}
