/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int n;
    int arr[MAX_SIZE];
    int uniqueArr[MAX_SIZE];

    // Read number of elements
    scanf("%d", &n);
    // Read the sorted array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    int uniqueCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            uniqueArr[uniqueCount++] = arr[i];
        }
    }
    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%d", uniqueArr[i]);
        if (i < uniqueCount - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}