#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0

typedef int QueueElement;

typedef struct queue {
    QueueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
} Queue;

void CreateQueue(Queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

int IsQueueEmpty(const Queue *q) {
    return (q->count == 0);
}

int IsQueueFull(const Queue *q) {
    return (q->count == MAXQUEUE);
}

void Append(Queue *q, QueueElement x) {
    if (IsQueueFull(q)) {
        printf("Queue Full\n");
        exit(1);
    } else {
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->items[q->rear] = x;
        q->count++;
    }
}

void Serve(Queue *q, QueueElement *x) {
    if (IsQueueEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    } else {
        *x = q->items[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        q->count--;
    }
}

int QueueSize(const Queue *q) {
    return q->count;
}

int main() {
    Queue myCque;
    CreateQueue(&myCque);
    QueueElement item;

    for(int i = 0; i <10; i++) {
        Append(&myCque, i);
    }

    printf("Queue Size: %d\n", QueueSize(&myCque));

    while (!IsQueueEmpty(&myCque)) {
        Serve(&myCque, &item);
        printf("Served: %d\n", item);
    }
    return 0;
}
