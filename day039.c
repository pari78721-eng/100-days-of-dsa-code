/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30  */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int minHeap[MAX];
int size = 0;
void insert(int value)
{
    if (size == MAX)
    {
        printf("Heap is full\n");
        return;
    }
    minHeap[size++] = value;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && minHeap[left] < minHeap[smallest])
            smallest = left;
        if (right < size && minHeap[right] < minHeap[smallest])
            smallest = right;
        if (smallest != i)
        {
            int temp = minHeap[i];
            minHeap[i] = minHeap[smallest];
            minHeap[smallest] = temp;
        }
    }
}
void extractMin()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", minHeap[0]);
    minHeap[0] = minHeap[--size];
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && minHeap[left] < minHeap[smallest])
            smallest = left;
        if (right < size && minHeap[right] < minHeap[smallest])
            smallest = right;
        if (smallest != i)
        {
            int temp = minHeap[i];
            minHeap[i] = minHeap[smallest];
            minHeap[smallest] = temp;
        }
    }
}
void peek()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", minHeap[0]);
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char operation[20];
        int value;
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "extractMin") == 0)
        {
            extractMin();
        }
        else if (strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }
    return 0;
}