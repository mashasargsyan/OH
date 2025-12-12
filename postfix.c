#include <stdio.h>
#include <ctype.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

int main() {
    char infix[MAX], postfix[MAX];
    int j = 0;

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix[j++] = c;      
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();  
        }
        else if (isOperator(c)) {
            while (top != -1 &&
                   precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}


