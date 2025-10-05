#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
        int val;
        struct Node* next;
} Node;

typedef struct {
        int size;
        Node* front;
        Node* rear;
} Queue;

bool empty(const Queue* q) {
        return q->size == 0;
}

int size(const Queue* q) {
        return q->size;
}

void enqueue(Queue* q, int val) {
        Node* tmp = malloc(sizeof(Node));
        tmp->val = val;
        tmp->next = NULL;
        if (empty(q)) {
                q->front = tmp;
                q->rear = tmp;
        } else {
                q->rear->next = tmp;
                q->rear = tmp;
        }
        q->size++;
}

void dequeue(Queue* q) {
        if (empty(q))
                return;
        Node* tmp = q->front->next;
        free(q->front);
        q->front = tmp;
        q->size--;
}

const Node* front(const Queue* q) {
        return q->front;
}

void print(const Queue* q) {
        const Node* tmp = q->front;
        while (tmp != NULL) {
                printf("%d ->", tmp->val);
                tmp = tmp->next;
        }
}


int main() {
        Queue q = {0, NULL, NULL};
        dequeue(&q);
        dequeue(&q);
        enqueue(&q, 5);
        printf("front is %d\n", front(&q)->val);
        enqueue(&q, 6);
        enqueue(&q, 9);
        printf("front is %d\n", front(&q)->val);
        dequeue(&q);
        enqueue(&q, 6);
        enqueue(&q, 7);
        printf("front is %d\n", front(&q)->val);
        dequeue(&q);
        print(&q);
        return 0;
}
