/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
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
    memset(hashTable, -1, sizeof(hashTable)); // initialize hash table
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        insert(u);
        insert(v);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (hashTable[hashFunction(i)] != -1)
            count++;
    }
    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");
    return 0;
}
