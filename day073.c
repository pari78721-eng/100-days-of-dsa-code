/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/
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
    char s[MAX];
    printf("Enter a string: ");
    scanf("%s", s);
    for (i = 0; i < MAX; i++)
        hashTable[i] = -1; // initialize hash table
    for (i = 0; s[i] != '\0'; i++)
        insert(s[i]); // insert characters into hash table
    for (i = 0; s[i] != '\0'; i++)
    {
        int key = s[i];
        int j = 0;
        int hashIndex;
        while (j < MAX)
        {
            hashIndex = (hashFunction(key) + j * j) % MAX;
            if (hashTable[hashIndex] == -1) // empty slot
                break;
            if (hashTable[hashIndex] == key)
            {
                printf("%c\n", key); // print first non-repeating character
                return 0;
            }
            j++;
        }
    }
    printf("$\n"); // print '$' if all characters repeat
    return 0;
}
