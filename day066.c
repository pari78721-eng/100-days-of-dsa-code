/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX]; // adjacency matrix
bool visited[MAX];
bool recStack[MAX];
int V; // number of vertices
bool dfs(int node)
{
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++)
    {
        if (graph[node][i])
        { // edge exists
            if (!visited[i])
            {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i])
            {
                return true; // cycle detected
            }
        }
    }
    recStack[node] = false; // backtrack
    return false;
}
bool hasCycle()
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
                return true;
        }
    }
    return false;
}
int main()
{
    V = 4;

    // Example graph
    // 0->1, 1->2, 2->0 → cycle
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
