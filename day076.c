/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>
#include <string.h>
#define MAX 100
int hashTable[MAX]; // hash table
int hashFunction(int key)
{
    return key % MAX;
}
void insert(int key)
{
    int i = 0;
    int hashIndex;
    while (i < MAX)
    {
        hashIndex = (hashFunction(key) + i * i) % MAX;
        if (hashTable[hashIndex] == -1) // empty slot
        {
            hashTable[hashIndex] = key;
            return;
        }
        i++;
    }
}
void search(int key)
{
    int i = 0;
    int hashIndex;
    while (i < MAX)
    {
        hashIndex = (hashFunction(key) + i * i) % MAX;
        if (hashTable[hashIndex] == -1) // empty slot
        {
            printf("NOT FOUND\n");
            return;
        }
        if (hashTable[hashIndex] == key)
        {
            printf("FOUND\n");
            return;
        }
        i++;
    }
}
int main()
{
    int n, i;
    char operation[10];
    for (i = 0; i < MAX; i++)
    {
        hashTable[i] = -1; // initialize hash table
    }
    printf("Enter number of operations: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter operation (insert/search) and key: ");
        scanf("%s %d", operation, &key);
        if (strcmp(operation, "insert") == 0)
        {
            insert(key);
        }
        else if (strcmp(operation, "search") == 0)
        {
            search(key);
        }
    }
    return 0;
}
