/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
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
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }
    printf("Sorted elements:\n");
    while (size > 0)
    {
        extractMin();
    }
    return 0;
}
