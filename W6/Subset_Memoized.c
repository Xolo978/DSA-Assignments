#include <stdbool.h>
#include <stdio.h>
int sum, n;
#define MAXRANGE 100
int minSum;
int dp[MAXRANGE][MAXRANGE];
bool subset(int arr[], int sum, int n) {
  if (sum == 0)
    return true;
  if (n == 0)
    return false;
  int idx = sum - minSum;
  if (idx < 0) {
    return 0;
  }
  if (dp[n][idx] != -1)
    return dp[n][idx];
  int res = subset(arr, sum, n - 1) || subset(arr, sum - arr[n - 1], n - 1);
  return dp[n][idx] = res;
}

void printSubset(int arr[], int sum, int n) {
  if (sum == 0) {
    printf("\n");
    return;
  }
  if (n == 0) {
    printf("No subset");
    return;
  }

  // Check if the sum can be found without using the current element(if yes then
  // skip it)
  if (subset(arr, sum, n - 1)) {
    printSubset(arr, sum, n - 1);
    return;
  }
  // Check if the sum can be found with using current element(if yes then print
  // it)
  if (subset(arr, sum - arr[n - 1], n - 1)) {
    printf("%d ", arr[n - 1]);
    printSubset(arr, sum - arr[n - 1], n - 1);
    return;
  }
}

int main() {
  int arr[] = {3, -2, 7, 5};
  int n = 4;
  int target = 8;
  minSum = 0;
  int maxSum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      minSum += arr[i];
    } else {
      maxSum += arr[i];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= maxSum - minSum; j++) {
      dp[i][j] = -1;
    }
  }
  printSubset(arr, target, n);
}
