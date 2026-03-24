/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = buildTree(arr, n);

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct TreeNode *lca = findLCA(root, n1, n2);
    if (lca)
        printf("%d\n", lca->data);
    else
        printf("LCA does not exist\n");

    return 0;
}