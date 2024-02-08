#include <stdio.h>
#include <stdlib.h>

#define MAXDEQUE 20
typedef int DequeElement;

typedef struct {
    DequeElement items[MAXDEQUE];
    int front;
    int rear;
    int count;
} Deque;

void CreateDeque(Deque *q) {
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

int IsDequeEmpty(const Deque *q) {
    return (q->count == 0);
}

int IsDequeFull(const Deque *q) {
    return (q->count == MAXDEQUE);
}

void ServeFront(Deque *q, DequeElement *x) {
    if (IsDequeEmpty(q)) {
        printf("Deque is empty, underflow\n");
        exit(1);
    }
    *x = q->items[q->front];
    q->front = (q->front + 1) % MAXDEQUE;
    q->count--;
}

void ServeRear(Deque *q, DequeElement *x) {
    if (IsDequeEmpty(q)) {
        printf("Deque is empty\n");
        exit(1);
    }
    *x = q->items[q->rear];
    q->rear = (q->rear - 1 + MAXDEQUE) % MAXDEQUE; // Ensure circular behavior
    q->count--;
}

void AppendRear(Deque *q, DequeElement x) {
    if (IsDequeFull(q)) {
        printf("Deque Full\n");
        exit(1);
    } else {
        q->rear = (q->rear + 1) % MAXDEQUE;
        q->items[q->rear] = x;
        q->count++;
    }
}

void AppendFront(Deque *q, DequeElement x) {
    if (IsDequeFull(q)) {
        printf("Deque Full\n");
        exit(1);
    } else {
        q->front = (q->front - 1 + MAXDEQUE) % MAXDEQUE;
        q->items[q->front] = x;
        if (IsDequeEmpty(q)) q->rear = q->front; // Handle case for first element
        q->count++;
    }
}

int main() {
    Deque myDeque;
    CreateDeque(&myDeque);
    DequeElement item;

    // Example usage
    AppendFront(&myDeque, 1);
    AppendRear(&myDeque, 2);
    ServeFront(&myDeque, &item);
    printf("Served from front: %d\n", item);
    ServeRear(&myDeque, &item);
    printf("Served from rear: %d\n", item);

    return 0;
}
