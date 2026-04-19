/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int primMST(int n)
{
    int parent[MAX];
    int key[MAX];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[minIndex][v] && !visited[v] && graph[minIndex][v] < key[v])
            {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }
    int totalWeight = 0;
    for (int i = 1; i < n; i++)
    {
        totalWeight += graph[parent[i]][i];
    }
    return totalWeight;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }
    int result = primMST(n);
    printf("%d\n", result);
    return 0;
}
