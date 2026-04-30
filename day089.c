/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int isPossible(int books[], int n, int m, int maxPages)
{
    int studentCount = 1; // Start with the first student
    int currentPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (books[i] > maxPages)
        {
            return 0; // A single book has more pages than maxPages, not possible
        }
        if (currentPages + books[i] > maxPages)
        {
            studentCount++;          // Allocate to next student
            currentPages = books[i]; // Start counting pages for the new student
            if (studentCount > m)
            {
                return 0; // More students needed than available
            }
        }
        else
        {
            currentPages += books[i]; // Add pages to current student's allocation
        }
    }
    return 1; // Allocation is possible within maxPages
}
int main()
{
    int n, m;
    printf("Enter the number of books and students: ");
    scanf("%d %d", &n, &m);

    int books[n];
    printf("Enter the number of pages in each book: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &books[i]);
    }

    // Sort the books by pages
    qsort(books, n, sizeof(int), compare);

    int low = books[0]; // Minimum possible max pages is the largest single book
    int high = 0;       // Maximum possible max pages is the sum of all books
    for (int i = 0; i < n; i++)
    {
        high += books[i];
    }

    int result = high; // Initialize result to the maximum possible value

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid))
        {
            result = mid;   // Update result to the current mid value
            high = mid - 1; // Try for a smaller maximum
        }
        else
        {
            low = mid + 1; // Try for a larger maximum
        }
    }

    printf("Minimum possible value of the maximum pages assigned to any student: %d\n", result);
    return 0;
}
