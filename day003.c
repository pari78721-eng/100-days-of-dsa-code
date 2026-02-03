/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons) */
#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int n, k;
    int arr[MAX_SIZE];
    int comparisons = 0;
    int foundIndex = -1;

    // Read the number of elements
    scanf("%d", &n);

    // Read the array elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Read the key to search
    scanf("%d", &k);

    // Perform linear search
    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == k)
        {
            foundIndex = i;
            break;
        }
    }

    // Output the result
    if (foundIndex != -1)
    {
        printf("Found at index %d\n", foundIndex);
    }
    else
    {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}