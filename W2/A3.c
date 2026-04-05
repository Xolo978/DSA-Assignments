#include <limits.h>
#include <stdio.h>
typedef struct Result {
  int max1;
  int max2;
  int min1;
  int min2;
} Res;

Res merge(Res left, Res right) {
  Res res;
  if (left.min1 < right.min1) {
    res.min1 = left.min1;
    res.min2 = left.min2 < right.min1 ? left.min2 : right.min1;
  } else {
    res.min1 = right.min1;
    res.min2 = right.min2 < left.min1 ? right.min2 : left.min1;
  }

  if (left.max1 > right.max1) {
    res.max1 = left.max1;
    res.max2 = left.max2 > right.max1 ? left.max2 : right.max1;
  } else {
    res.max1 = right.max1;
    res.max2 = right.max2 > left.max1 ? right.max2 : left.max1;
  }
  return res;
}

Res find(int arr[], int low, int high) {
  Res res;
  if (low == high) {
    res.max1 = res.min1 = arr[low];
    res.min2 = INT_MAX;
    res.max2 = INT_MIN;
    return res;
  }
  if (high == low + 1) {
    if (arr[low] < arr[high]) {
      res.min1 = arr[low];
      res.max1 = arr[high];
      res.min2 = arr[high];
      res.max2 = arr[low];
    } else {
      res.min1 = arr[high];
      res.max1 = arr[low];
      res.min2 = arr[low];
      res.max2 = arr[high];
    }
    return res;
  }
  int mid = (low + high) / 2;
  Res left = find(arr, low, mid);
  Res right = find(arr, mid + 1, high);
  return merge(left, right);
}

int main() {
  int arr[] = {12, 35, 2, 10, 34, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  if (n < 2) {
    printf("Array needs at least two elements.\n");
    return 0;
  }

  Res res = find(arr, 0, n - 1);

  printf("Second Smallest: %d\n", res.min2);
  printf("Second Largest: %d\n", res.max2);

  return 0;
}
