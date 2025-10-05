#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* top;
} Stack;

bool empty(const Stack* s) {
    return s->size == 0;
}

int size(const Stack* s) {
    return s->size;
}

void push(Stack* s, int val) {
    Node* tmp = malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = s->top;
    s->top = tmp;
    s->size++;
}

void pop(Stack* s) {
    if (empty(s))
        return;
    Node* tmp = s->top->next;
    free(s->top);
    s->top = tmp;
    s->size--;
}

const Node* top(const Stack* s) {
    return s->top;
}

void print(const Stack* s) {
    const Node* tmp = s->top;
    while (tmp != NULL) {
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack s = {0, NULL};

    pop(&s); 
    push(&s, 5);
    printf("top is %d\n", top(&s)->val);
    push(&s, 6);
    push(&s, 9);
    printf("top is %d\n", top(&s)->val);
    pop(&s);
    printf("top is %d\n", top(&s)->val);
    push(&s, 7);
    print(&s);

    return 0;
}

