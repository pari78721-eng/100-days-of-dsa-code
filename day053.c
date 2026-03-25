/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
Example:
Input:
7
1 2 3 4 5 6 7
Output:
4
2
1 5 6
3
7
Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode *buildTree(int arr[], int n)
{
    if (n == 0)
        return NULL;

    struct TreeNode *root = createNode(arr[0]);
    struct TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    for (int i = 1; i < n; i++)
    {
        struct TreeNode *current = queue[front++];

        if (arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }

        if (++i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
    }
    return root;
}
struct TreeNode *findLCA(struct TreeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct TreeNode *leftLCA = findLCA(root->left, n1, n2);
    struct TreeNode *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
void verticalOrder(struct TreeNode *root, int hd, int minHd, int maxHd, int *columns[100])
{
    if (root == NULL)
        return;

    if (hd < minHd)
        minHd = hd;
    if (hd > maxHd)
        maxHd = hd;

    columns[hd + 50][0]++;                              // Increment count of nodes in this vertical line
    columns[hd + 50][columns[hd + 50][0]] = root->data; // Store node data

    verticalOrder(root->left, hd - 1, minHd, maxHd, columns);
    verticalOrder(root->right, hd + 1, minHd, maxHd, columns);
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = buildTree(arr, n);

    int *columns[100] = {0}; // Array to store nodes in each vertical line
    for (int i = 0; i < 100; i++)
        columns[i] = (int *)malloc(101 * sizeof(int)); // First element will store count

    int minHd = 0, maxHd = 0;
    verticalOrder(root, 0, &minHd, &maxHd, columns);

    for (int hd = minHd; hd <= maxHd; hd++)
    {
        for (int j = 1; j <= columns[hd + 50][0]; j++)
            printf("%d ", columns[hd + 50][j]);
        printf("\n");
    }

    return 0;
}
