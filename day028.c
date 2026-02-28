/*  Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop  */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Create new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
// Insert at end and make circular
struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = newNode(data);
    if (head == NULL)
    {
        temp->next = temp; // Point to itself for circular
        return temp;
    }

    struct Node *current = head;
    while (current->next != head) // Traverse to last node
        current = current->next;

    current->next = temp; // Link last node to new node
    temp->next = head;    // Link new node back to head
    return head;
}
// Traverse circular linked list
void traverse(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we return to head
    printf("\n");
}
int main()
{
    int n, data;
    struct Node *head = NULL;

    // Read number of elements
    scanf("%d", &n);

    // Read and insert elements into circular linked list
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }

    // Traverse and print circular linked list
    traverse(head);

    return 0;
}
