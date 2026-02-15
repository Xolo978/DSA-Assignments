
int max(int a, int b) { return a > b ? a : b; }

int knapRecurse(int wt[], int val[], int n, int c) {
  if (n == 0 || c == 0) {
    return 0;
  } else if (wt[n - 1] > c) {
    return knapRecurse(wt, val, n - 1, c);
  } else {
    return max(knapRecurse(wt, val, n - 1, c),
               val[n - 1] + knapRecurse(wt, val, n - 1, c - wt[n - 1]));
  }
}
