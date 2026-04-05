#include <stdio.h>
float findMedian(int arr1[], int arr2[], int n) {

  int i = 0;
  int j = 0;
  int m1 = -1;
  int m2 = -1;
  int count = 0;
  while (i < n && j < n && count <= n) {
    m2 = m1;
    if (arr1[i] < arr2[j]) {
      m1 = arr1[i++];
    } else {
      m1 = arr2[j++];
    }
    count++;
  }
  while (i < n && count <= n) {
    m2 = m1;
    m1 = arr1[i++];
    count++;
  }
  while (j < n && count <= n) {
    m2 = m1;
    m1 = arr2[j++];
    count++;
  }

  return (m1 + m2) / 2.0;
}
int main() {
  int arr1[] = {2, 3, 5};
  int arr2[] = {-1, 4, 9};
  printf("%.2f\n", findMedian(arr1, arr2, 3));
}
