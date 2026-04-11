/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX]; // adjacency matrix
int V;               // number of vertices
void bellmanFord(int src)
{
    int dist[MAX];
    // Initialize distances
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < V; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                printf("NEGATIVE CYCLE\n");
                return;
            }
        }
    }

    // Print shortest distances from source
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main()
{
    V = 5;

    // Example graph (adjacency matrix with weights)
    graph[0][1] = 10;
    graph[0][2] = 5;
    graph[1][2] = 2;
    graph[1][3] = 1;
    graph[2][1] = 3;
    graph[2][3] = 9;
    graph[2][4] = 2;
    graph[3][4] = 4;
    graph[4][3] = -7; // Negative weight edge

    bellmanFord(0);
    return 0;
}
