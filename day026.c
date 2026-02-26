/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
// Create new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
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

    struct Node *new_node = newNode(data);
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}
// Traverse and print
void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, data;
    struct Node *head = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Read and insert nodes
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }

    // Traverse and print the linked list
    traverse(head);
    printf("\n");

    return 0;
}
