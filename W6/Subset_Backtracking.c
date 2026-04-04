#include <stdio.h>
void backtrack(int arr[], int subset[], int n, int k, int target) {
  if (target == 0) {
    for (int t = 0; t < k; t++) {
      printf("%d ", subset[t]);
    }
    printf("\n");
    return;
  }
  if (n == 0 || target < 0) {
    return;
  }
  // Skip
  backtrack(arr, subset, n - 1, k, target);
  // Include
  subset[k] = arr[n - 1];
  backtrack(arr, subset, n - 1, k + 1, target - arr[n - 1]);
}

int main() {
  int set[] = {2, 5, 1, 0};
  int n = 4;
  int target = 7;
  int arr[n];
  backtrack(set, arr, n, 0, target);
}
