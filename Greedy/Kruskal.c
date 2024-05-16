#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct subset {
    int parent;
    int rank;
} subset;

int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    Edge edges[V*V];
    int e = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[e].src = i;
                edges[e].dest = j;
                edges[e].weight = graph[i][j];
                e++;
            }
        }
    }

    subset *subsets = (subset*) malloc(V * sizeof(subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    e = 0;  
    int i = 0;  
    while (e < V - 1 && i < V*V) {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            printf("%d -- %d == %d\n", next_edge.src, next_edge.dest, next_edge.weight);
            Union(subsets, x, y);
            e++;
        }
    }
}

int main() {
    int V = 4;  
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };
    KruskalMST(graph, V);
    return 0;
}