/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
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
int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int countLeafNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main()
{
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the node values (use -1 for NULL): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct TreeNode *root = buildTree(arr, n);
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the tree: %d\n", leafCount);

    return 0;
}