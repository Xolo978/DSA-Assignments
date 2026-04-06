#include <limits.h>
#include <stdio.h>

int findMinCost(int key[], int mst[]) {
  int min = INT_MAX;
  return min;
}
void printMST(int parent[], int vertices, int graph[vertices][vertices]) {
  printf("Edge \tWeight\n");
  for (int i = 1; i < vertices; i++)
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int vertices, int start, int graph[vertices][vertices]) {
  int dist[vertices];
  int mst[vertices];
  int parent[vertices];

  for (int i = 0; i < vertices; i++) {
    mst[i] = 0;
    dist[i] = INT_MAX;
  }
  dist[start] = 0;
  parent[vertices] = -1;

  for (int count = 0; count < vertices - 1; count++) {
    int u = findMinCost(dist, mst);
    mst[u] = 1;
    // Now for the u node relax the rest

    for (int v = 0; v < vertices; v++) {
      if (graph[u][v] && mst[v] == 0 && graph[u][v] < dist[v]) {
        parent[v] = u;
        dist[v] = graph[u][v];
      }
    }
  }
  printMST(parent, vertices, graph);
}
