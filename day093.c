/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq and prefix sum arrays, place elements in output array based on freq, copy back to original array.*/
#include <stdio.h>
#define MAX_SIZE 100
void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int freq[max + 1];
    for (int i = 0; i <= max; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        freq[i] += freq[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
