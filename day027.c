/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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
// Get length of list
int length(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// Find intersection
struct Node *findIntersection(struct Node *head1, struct Node *head2)

{
    int len1 = length(head1);
    int len2 = length(head2);
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
int main()
{
    int n, m, data;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // Read first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head1 = insert(head1, data);
    }

    // Read second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &data);
        head2 = insert(head2, data);
    }

    // Find intersection
    struct Node *intersection = findIntersection(head1, head2);
    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
