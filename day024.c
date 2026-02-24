/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
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
// Insert at end
struct Node *insert(struct Node *head, int data)
{
    if (head == NULL)
        return newNode(data);

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode(data);
    return head;
}
// Delete first occurrence of key
struct Node *deleteKey(struct Node *head, int key)
{
    if (head == NULL)
        return head;

    // If head node itself holds the key to be deleted
    if (head->data == key)
    {
        struct Node *temp = head;
        head = head->next; // Change head
        free(temp);        // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    // If key was not present in linked list
    if (temp->next == NULL)
        return head;

    // Unlink the node from linked list
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next; // Change next only

    free(toDelete); // Free memory
    return head;
}