#include <stdio.h>

#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int n;             // Number of vertices

// DFS function
void dfs(int vertex) {
    printf("%d ", vertex);  // Print the current vertex
    visited[vertex] = 1;    // Mark the vertex as visited

    // Recur for all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Remove for directed graphs
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
