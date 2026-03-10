/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int priorityQueue[MAX];
int size = 0;
void insert(int value)
{
    if (size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    priorityQueue[size++] = value;
}
void delete()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (priorityQueue[i] < priorityQueue[minIndex])
        {
            minIndex = i;
        }
    }
    printf("%d\n", priorityQueue[minIndex]);
    for (int i = minIndex; i < size - 1; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    size--;
}
void peek()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (priorityQueue[i] < priorityQueue[minIndex])
        {
            minIndex = i;
        }
    }
    printf("%d\n", priorityQueue[minIndex]);
}
int main()
{
    insert(10);
    insert(20);
    delete();
    peek();
    return 0;
}
