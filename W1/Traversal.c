#include <stdio.h>
#define MAX 100

int matrix[MAX][MAX];
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int n) {
  if (rear == MAX - 1) {
    printf("Full");
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear++;
  queue[rear] = n;
}

int dequeue() {
  if (front == -1 || front > rear) {
    return -1;
  }
  return queue[front++];
}

void BFS(int start, int n, int visited[MAX]) {
  int i, v;
  enqueue(start);
  visited[start] = 1;
  while ((v = dequeue()) != -1) {
    printf("%d\t", v);
    for (int i = 0; i < n; i++) {
      if (matrix[v][i] && !visited[i]) {
        enqueue(i);
        visited[i] = 1;
      }
    }
  }
  printf("\n");
}

void DFS(int v, int n, int visited[]) {
  visited[v] = 1;
  printf("%d\t", v);
  for (int i = 0; i < n; i++) {
    if (matrix[v][i] && !visited[i]) {
      DFS(i, n, visited);
    }
  }
}

int main() {
  int n, e;
  printf("Enter number of vertices: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matrix[i][j] = 0;

  printf("Enter number of edges: ");
  scanf("%d", &e);

  printf("Enter edges as (i j):\n");
  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    matrix[u][v] = 1;
    matrix[v][u] = 1;
  }

  int start;
  printf("Enter starting vertex: ");
  scanf("%d", &start);
  int visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  printf("BFS: \n");
  BFS(start, n, visited);
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  printf("\nDFS: \n");
  DFS(start, n, visited);
  printf("\n");
}
