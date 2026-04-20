/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int dijkstra(int n, int source)
{
    int dist[MAX];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[minIndex][v] && !visited[v] && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }
    return dist;
}
int main()
{
    int n, m, u, v, w, source;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }
    scanf("%d", &source);
    int *distances = dijkstra(n, source - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", distances[i]);
    }
    return 0;
}
