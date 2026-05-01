/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>
#include <stdlib.h>
int isPossible(int boards[], int n, int k, int maxTime)
{
    int painterCount = 1; // Start with the first painter
    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (boards[i] > maxTime)
        {
            return 0; // A single board takes more time than maxTime, not possible
        }
        if (currentTime + boards[i] > maxTime)
        {
            painterCount++;          // Allocate to next painter
            currentTime = boards[i]; // Start counting time for the new painter
            if (painterCount > k)
            {
                return 0; // More painters needed than available
            }
        }
        else
        {
            currentTime += boards[i]; // Add time to current painter's allocation
        }
    }
    return 1; // Allocation is possible within maxTime
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &boards[i]);
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        high += boards[i]; // Maximum time if one painter paints all boards
    }

    int result = high; // Initialize result with the maximum possible time
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Midpoint of the current range
        if (isPossible(boards, n, k, mid))
        {
            result = mid;   // Update result if allocation is possible
            high = mid - 1; // Try to find a smaller maximum time
        }
        else
        {
            low = mid + 1; // Increase the minimum time
        }
    }

    printf("%d\n", result); // Print the minimum time required to paint all boards
    return 0;
}
