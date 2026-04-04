#include <stdio.h>
int recurse(int arr[], int c, int n) {
  if (c == 0) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }

  return recurse(arr, c, n - 1) || recurse(arr, c - arr[n - 1], n - 1);
}

int main() {
  int arr[] = {3, -2, 7, 5};
  int target = -100;
  printf("%d\n", recurse(arr, target, 4));
}
