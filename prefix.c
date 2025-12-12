#include <stdio.h>
#include <string.h>
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


void reverse(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


void swapParens(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int j = 0;

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    reverse(infix);
    swapParens(infix);

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

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
        else { 
            while (top != -1 &&
                   precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);
    return 0;
}

