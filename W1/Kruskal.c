#include <asm-generic/errno.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Edge {
  int u;
  int v;
  int weight;
} Edge;

typedef struct DisjointSet {
  int *rank;
  int *parent;
  int n;
} DS;

DS *init(int n) {
  DS *set = malloc(sizeof(DS));
  set->n = n;
  set->parent = malloc(n * sizeof(int));
  set->rank = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    set->rank[i] = 0;
    set->parent[i] = i;
  }
  return set;
}

int findUltimateParent(DS *set, int v) {
  if (v == set->parent[v]) {
    return v;
  }
  set->parent[v] = findUltimateParent(set, set->parent[v]);
  return set->parent[v];
}

void unionByRank(DS *set, int u, int v) {
  int ulp_u = findUltimateParent(set, u);
  int ulp_v = findUltimateParent(set, v);
  if (ulp_u == ulp_v)
    return;
  if (set->rank[ulp_u] < set->rank[ulp_v]) {
    set->parent[ulp_u] = ulp_v;
  } else if (set->rank[ulp_v] < set->rank[ulp_u]) {
    set->parent[ulp_v] = ulp_u;
  } else {
    set->parent[ulp_u] = ulp_v;
    set->rank[ulp_v]++;
  }
}

int cmp(const void *a, const void *b) {
  int w1 = ((Edge *)a)->weight;
  int w2 = ((Edge *)b)->weight;
  return w1 - w2;
}

Edge *kruskal(Edge edge[], int vertices, int edges) {
  qsort(edge, edges, sizeof(Edge), cmp);
  DS *ds = init(vertices);

  Edge *mst = malloc((vertices - 1) * sizeof(Edge));
  int cost = 0;
  int size = 0;
  for (int i = 0; i < edges; i++) {
    int u = edge[i].u;
    int v = edge[i].v;

    int ulp_u = findUltimateParent(ds, u);
    int ulp_v = findUltimateParent(ds, v);
    // If no cycle
    if (ulp_u != ulp_v) {
      mst[size++] = edge[i];
      cost += edge[i].weight;
      unionByRank(ds, u, v);
    }
    if (size == vertices - 1) {
      break;
    }
  }
  return mst;
}

int main() {
  int vertices = 4;
  int edge = 5;
  Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
  Edge *mst = kruskal(edges, vertices, edge);
  for (int i = 0; i < vertices - 1; i++) {
    printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].weight);
  }
}
