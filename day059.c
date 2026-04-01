/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
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
