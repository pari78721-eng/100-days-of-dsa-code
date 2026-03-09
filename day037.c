/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20  */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int priorityQueue[MAX];
int size = 0;
void insert(int value)
{
    if (size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    priorityQueue[size++] = value;
}
void delete()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (priorityQueue[i] < priorityQueue[minIndex])
        {
            minIndex = i;
        }
    }
    printf("%d\n", priorityQueue[minIndex]);
    for (int i = minIndex; i < size - 1; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    size--;
}
void peek()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (priorityQueue[i] < priorityQueue[minIndex])
        {
            minIndex = i;
        }
    }
    printf("%d\n", priorityQueue[minIndex]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char operation[10];
        int value;
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "delete") == 0)
        {
            delete();
        }
        else if (strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }
    return 0;
}
