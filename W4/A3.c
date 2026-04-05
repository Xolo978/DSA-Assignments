#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
  if (low <= high) {
    int pi = partition(arr, low, high);
    if (pi == k)
      return arr[pi];
    if (pi > k)
      return quickSelect(arr, low, pi - 1, k);
    return quickSelect(arr, pi + 1, high, k);
  }
  return -1;
}

int main() {
  int arr[] = {12, 3, 5, 7, 4, 19, 26};
  int n = sizeof(arr) / sizeof(arr[0]);
  int mid = n / 2;

  int median = quickSelect(arr, 0, n - 1, mid);
  int leftNeighbor = (mid > 0) ? quickSelect(arr, 0, n - 1, mid - 1) : -1;
  int rightNeighbor = (mid < n - 1) ? quickSelect(arr, 0, n - 1, mid + 1) : -1;

  printf("Median: %d\n", median);
  if (leftNeighbor != -1)
    printf("Left Neighbor: %d\n", leftNeighbor);
  if (rightNeighbor != -1)
    printf("Right Neighbor: %d\n", rightNeighbor);

  return 0;
}
