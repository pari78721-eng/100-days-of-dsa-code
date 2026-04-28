/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>
int integerSquareRoot(int n);
int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("The integer square root of %d is %d\n", n, result);

    return 0;
}
