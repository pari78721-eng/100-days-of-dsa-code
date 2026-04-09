/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX]; // adjacency matrix
int inDegree[MAX];
int V; // number of vertices
void topologicalSort()
{
    int queue[MAX];
    int front = 0, rear = 0;

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    while (front < rear)
    {
        int node = queue[front++]; // Dequeue
        printf("%d ", node);       // Print the vertex

        // Decrease in-degree of neighbors
        for (int i = 0; i < V; i++)
        {
            if (graph[node][i])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    queue[rear++] = i; // Enqueue if in-degree becomes 0
                }
            }
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

    // Calculate in-degrees
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j])
            {
                inDegree[j]++;
            }
        }
    }

    printf("Topological Sort: ");
    topologicalSort();
    printf("\n");

    return 0;
}
