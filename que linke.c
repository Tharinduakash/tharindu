#include <stdio.h>
#include <stdlib.h>

typedef int QueueElement;

typedef struct node {
    QueueElement entry;
    struct node *next;
} QueueNode;

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int count;
    Boolean full;
} Queue;

// CreateQueue
void CreateQueue(Queue *q) {
    q->count = 0;
    q->full = FALSE;
    q->front = q->rear = NULL;
}

// IsQueueEmpty
Boolean IsQueueEmpty(const Queue *q) {
    return (q->front == NULL);
}

// IsQueueFull
Boolean IsQueueFull(const Queue *q) {
    return (q->full);
}

void Serve(QueueElement *x, Queue *q) {
    QueueNode *np;
    if(IsQueueEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    else {
        *x = q->front->entry;
        np = q->front;
        q->front = q->front->next;
        q->count--;
        if(q->front == NULL) {
            q->rear = NULL;
        }
        free(np);
    }
}

void Append(QueueElement x, Queue *q) {
    QueueNode *np = (QueueNode *)malloc(sizeof(QueueNode));
    if(np == NULL) {
        printf("Not enough memory\n");
        q->full = TRUE;
    }
    else {
        np->entry = x;
        np->next = NULL;
        if(IsQueueEmpty(q)) {
            q->front = q->rear = np;
        }
        else {
            q->rear->next = np;
            q->rear = np;
        }
        q->count++;
    }
}

int main() {
    Queue myque;
    CreateQueue(&myque);

    for(int i = 0; i < 10; i++) {
        Append(i, &myque);
    }

    QueueElement x;
    while (!IsQueueEmpty(&myque)) {
        Serve(&x, &myque);
        printf("Served: %d\n", x);
    }
    return 0;
}
