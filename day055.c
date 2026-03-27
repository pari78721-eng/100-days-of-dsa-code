/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct Queue
{
    struct TreeNode *arr[1000];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = 0;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void enqueue(struct Queue *q, struct TreeNode *node)
{
    q->arr[q->rear++] = node;
}

struct TreeNode *dequeue(struct Queue *q)
{
    return q->arr[q->front++];
}

// Right View Function
void rightView(struct TreeNode *root)
{
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++)
        {
            struct TreeNode *curr = dequeue(&q);

            // If last node of level
            if (i == size - 1)
                printf("%d ", curr->val);

            if (curr->left)
                enqueue(&q, curr->left);

            if (curr->right)
                enqueue(&q, curr->right);
        }
    }
}