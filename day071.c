/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#define MAX 100
int hashTable[MAX]; // hash table
int m;              // size of hash table
int hashFunction(int key)
{
    return key % m;
}
void insert(int key)
{
    int i = 0;
    int hashIndex;
    while (i < m)
    {
        hashIndex = (hashFunction(key) + i * i) % m;
        if (hashTable[hashIndex] == -1) // empty slot
        {
            hashTable[hashIndex] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}
void search(int key)
{
    int i = 0;
    int hashIndex;
    while (i < m)
    {
        hashIndex = (hashFunction(key) + i * i) % m;
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
    printf("NOT FOUND\n");
}
int main()
{
    int n, q;
    scanf("%d", &m); // size of hash table
    scanf("%d", &q); // number of queries
    for (int i = 0; i < MAX; i++)
    {
        hashTable[i] = -1; // initialize hash table
    }
    for (int i = 0; i < q; i++)
    {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);
        if (operation[0] == 'I') // INSERT
        {
            insert(key);
        }
        else if (operation[0] == 'S') // SEARCH
        {
            search(key);
        }
    }
    return 0;
}