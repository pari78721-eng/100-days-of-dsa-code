/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
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
        else
        {
            printf("Invalid operation\n");
        }
    }
    return 0;
}
