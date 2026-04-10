/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX]; // adjacency matrix
int V;               // number of vertices
void dijkstra(int src)
{
    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        // Find the vertex with the minimum distance
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        // Update distances of neighbors
        for (int v = 0; v < V; v++)
        {
            if (graph[minIndex][v] && !visited[v] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
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
    graph[4][3] = 6;

    int source = 0;
    dijkstra(source);

    return 0;
}
