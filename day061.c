/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
void addEdge(int u, int v, int directed)
{
    graph[u][v] = 1;
    if (!directed)
        graph[v][u] = 1;
}
void printGraph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, m, directed;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Is the graph directed? (1 for yes, 0 for no): ");
    scanf("%d", &directed);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v, directed);
    }
    printf("Adjacency Matrix:\n");
    printGraph(n);
    return 0;
}
