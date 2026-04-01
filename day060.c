/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Create new node
struct TreeNode *newNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// Find index of value in array
int findIndex(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
// Build tree from inorder and postorder
struct TreeNode *buildTree(int inorder[], int postorder[], int inStart, int in End, int *postIndex)
{
    if (inStart > inEnd)
        return NULL;

    struct TreeNode *node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return node;

    int inIndex = findIndex(inorder, inStart, inEnd, node->data);

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}
// Preorder traversal
void preorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int N;
    scanf("%d", &N);
    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);
    int postIndex = N - 1;
    struct TreeNode *root = buildTree(inorder, postorder, 0, N - 1, &postIndex);
    preorder(root);
    return 0;
}
