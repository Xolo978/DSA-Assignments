#include <stdio.h>
int firstOccur(int arr[], int n, int x) {
  int index = -1;
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
      index = mid;
      high = mid - 1;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return index;
}

int lastOccur(int arr[], int n, int x) {
  int index = -1;
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
      index = mid;
      low = mid + 1;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return index;
}
int count(int arr[], int n, int x) {
  int last = lastOccur(arr, n, x);
  int first = firstOccur(arr, n, x);
  if (first == -1) {
    return -1;
  }
  return (last - first) + 1;
}

int main() {
  int arr[5] = {0, 1, 1, 1, 2};
  printf("%d\n", count(arr, 5, 1));
}
