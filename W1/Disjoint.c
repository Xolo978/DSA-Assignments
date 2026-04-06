// Union connects 2 vertices
// This d.s helpe us check if one vertex is in relation with another(const time)
/**
 * We have to connect nodes (u,v)
 * Initialize parent array as parent[i] = i.(All nodes their own parents)
 * Initialize rank as 0, here rank means number of nodes beneath the node;
 *
 * UnionbyRank(int u, int v)
 * 1.Find ultimate parent of u(pu) and ultimate parent of v(pv)
 * 2.Compare the ranks of pu and pv, whichever is smaller connect to larger
 * 3.If they are same attach anyone and incerase rank of the attached one
 *
 **/
#include <stdlib.h>
typedef struct DisjointSet {
  int n;
  int *parent;
  int *rank;
} DS;

DS *init(int nodes) {
  DS *set = malloc(sizeof(DS));
  set->n = nodes;
  set->parent = malloc(nodes * sizeof(int));
  set->rank = malloc(nodes * sizeof(int));
  for (int i = 0; i < nodes; i++) {
    set->rank[i] = 0;
    set->parent[i] = i;
  }
  return set;
}

int findUltimateParent(DS *set, int v) {
  // If the node is its own parent then this is the ultimate parent
  /**
   Example: This is the graph:
   0->1->2->3
   parent[] = {0,0,1,2}
   Here 0 is the ultimate parent
   * **/
  if (v == set->parent[v]) {
    return v;
  }
  // Here we do path compression to connect all the nodes to its ultimate_parent
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
    // If equal connect anyone and update rank to connected one
    set->parent[ulp_u] = ulp_v;
    set->rank[ulp_v]++;
  }
}
