/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX]; // adjacency matrix
int visited[MAX];
int V; // number of vertices
void dfs(int node)
{
    visited[node] = 1; // mark as visited

    for (int i = 0; i < V; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
    printf("%d ", node); // print after visiting all neighbors
}
void topologicalSort()
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    V = 6;

    // Example DAG
    // 5->0, 5->2, 4->0, 4->1, 2->3, 3->1
    graph[5][0] = 1;
    graph[5][2] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    printf("Topological Sort: ");
    topologicalSort();
    printf("\n");

    return 0;
}
