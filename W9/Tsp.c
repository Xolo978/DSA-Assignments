#include <stdio.h>
#define N 4

int cost[N][N] = {
    {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

int visited[N];
int minCost;

void TSP(int start, int curr, int count, int currCost) {
  if (count == N && cost[curr][start]) {
    int total = currCost + cost[curr][0];
    if (total < minCost) {
      minCost = total;
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    if (!visited[i] && cost[curr][i]) {
      visited[i] = 1;
      TSP(start, i, count + 1, currCost + cost[curr][i]);
      visited[i] = 0;
    }
  }
}

int main() {
  visited[0] = 1;
  TSP(0, 0, 1, 0);
  printf("Mincost %d", minCost);
}
