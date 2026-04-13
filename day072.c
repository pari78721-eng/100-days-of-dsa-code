/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/
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
    int key;
    scanf("%d", &m); // size of hash table
    scanf("%d", &n); // number of operations
    for (i = 0; i < MAX; i++)
        hashTable[i] = -1; // initialize hash table
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", operation, &key);
        if (strcmp(operation, "INSERT") == 0)
            insert(key);
        else if (strcmp(operation, "SEARCH") == 0)
            search(key);
    }
    return 0;
}
