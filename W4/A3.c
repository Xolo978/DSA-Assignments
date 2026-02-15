void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int l, int h) {
  int pivot = arr[h];
  int i = l - 1;
  for (int j = l; j < h; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[h]);
  return i + 1;
}

int find(int arr[], int l, int h, int k) {
  if (l <= h) {
    int pivotIndex = partition(arr, l, h);
    if (pivotIndex == k) {
      return arr[pivotIndex];
    } else if (pivotIndex > k) {
      return find(arr, l, pivotIndex - 1, k);
    } else {
      return find(arr, pivotIndex + 1, h, k);
    }
  }
  return -1;
}
