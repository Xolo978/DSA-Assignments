int memo[100][100];

int max(int a, int b) { return a > b ? a : b; }

int knapMemoized(int wt[], int val[], int c, int n) {
  if (n == 0 || c == 0) {
    return 0;
  }
  if (wt[n - 1] > 0) {
    memo[n][c] = knapMemoized(wt, val, c, n - 1);
    return memo[n][c];
  } else {
    memo[n][c] = max(val[n - 1] + knapMemoized(wt, val, c - wt[n - 1], n - 1),
                     knapMemoized(wt, val, c, n - 1));
    return memo[n][c];
  }
}
