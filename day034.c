/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *top = NULL;
void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop()
{
    if (top != NULL)
    {
        int value = top->data;
        Node *temp = top;
        top = top->next;
        free(temp);
        return value;
    }
    return -1; // Stack underflow
}
int main()
{
    char postfix[MAX];
    scanf("%s", postfix);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];
        if (token >= '0' && token <= '9')
        {
            push(token - '0'); // Convert char to int and push
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            switch (token)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            push(result); // Push the result back to stack
        }
    }
    printf("%d\n", pop()); // Final result
    return 0;
}
