/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int adj[MAX][MAX], int n, int node)
{
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            dfs(adj, n, i);
        }
    }
}

int main()
{
    int n, s;
    int adj[MAX][MAX];

    // Input number of vertices
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Call DFS
    dfs(adj, n, s);

    return 0;
}