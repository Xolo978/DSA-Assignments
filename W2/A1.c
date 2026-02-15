#include <stdio.h>
void find(int arr[], int target, int n) {
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int sum = arr[l] + arr[r];
    if (sum == target) {
      printf("Indexes are: %d,%d\n", l, r);
      return;
    }
    if (sum < target) {
      l++;
    } else {
      r--;
    }
  }
  printf("Cannot find sum\n");
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int target = 7;
  find(arr, target, 5);
}
