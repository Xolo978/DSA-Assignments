#include <stdio.h>
int findInversion(int arr[], int left, int mid, int right, int temp[]) {
  int i = left;
  int j = mid + 1;
  int count = 0;
  int k = left;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      count += (mid - i + 1);
    }
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }
  return count;
}

int merge(int arr[], int temp[], int l, int r) {
  int count = 0;
  if (l < r) {
    int mid = (l + r) / 2;
    count += merge(arr, temp, l, mid);
    count += merge(arr, temp, mid + 1, r);
    count += findInversion(arr, l, mid, r, temp);
  }
  return count;
}

int main() {
  int arr[5] = {2, 4, 1, 3, 5};
  int temp[5];
  printf("%d", merge(arr, temp, 0, 4));
}
