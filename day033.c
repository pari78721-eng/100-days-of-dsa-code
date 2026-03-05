/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value)
{
    if (top < MAX - 1)
    {
        top++;
        stack[top] = value;
    }
}
int pop()
{
    if (top >= 0)
    {
        int value = stack[top];
        top--;
        return value;
    }
    return -1; // Stack underflow
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int main()
{
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    int j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        char token = infix[i];
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z'))
        {
            postfix[j++] = token; // Add operand to postfix
        }
        else
        { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] = pop(); // Pop higher or equal precedence operators
            }
            push(token); // Push current operator
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop(); // Pop remaining operators
    }
    postfix[j] = '\0'; // Null-terminate the string
    printf("%s\n", postfix);
    return 0;
}
