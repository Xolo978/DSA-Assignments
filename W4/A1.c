#include <stdio.h>
int findBitonic(int arr[], int l, int r) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return arr[mid];
    }
    if (arr[mid] > arr[mid + 1]) {
      return findBitonic(arr, l, mid - 1);
    } else {
      return findBitonic(arr, mid + 1, r);
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 7, 4, 2};
  printf("%d\n", findBitonic(arr, 0, 5));
}
