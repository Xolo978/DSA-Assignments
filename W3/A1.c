typedef struct result {
  int row;
  int col;
} result;
result search(int row, int column, int matrix[row][column], int target) {
  int low = 0;
  int high = (column * row) - 1;
  result res;
  while (low <= high) {
    int mid = (low + high) / 2;
    int r = mid / column;
    int c = mid % column;
    if (matrix[r][c] == target) {
      res.row = r;
      res.col = c;
      return res;
    } else if (matrix[r][c] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  res.col = -1;
  res.row = -1;
  return res;
}
