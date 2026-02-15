float findMedian(int arr1[], int arr2[], int n) {
  int i = 0;
  int j = 0;
  int m1 = -1;
  int m2 = -1;
  // Only need to reach the middle of both arrays for
  for (int count = 0; count <= n; count++) {
    m2 = m1;
    if (i < n && j < n) {
      if (arr1[i] < arr2[j]) {
        m1 = arr1[i++];
      } else {
        m1 = arr2[j++];
      }
    } else if (i < n) {
      m1 = arr1[i++];
    } else {
      m1 = arr2[j++];
    }
  }
  return (m1 + m2) / 2.0;
}
