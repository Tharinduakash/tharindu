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

// CreateQueue
void CreateQueue(Queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

int IsQueueEmpty(Queue *q) {
    return (q->count == 0);
}

int IsQueueFull(Queue *q) {
    return (q->count == MAXQUEUE);
}
//Append
void Append(Queue *q, QueueElement x){
    if (IsQueueFull(q)){
        printf("Queue Full\n");
        exit(1);
    }
    else {
        q->items[++(q->rear)] = x;
        q->count++;
    }
}

//Serve
void Serve(Queue *q, QueueElement *x){
    if (IsQueueEmpty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    *x = q->items[(q->front)++];
    q->count--;
}

int main() {
    Queue myque;
    CreateQueue(&myque); // Initialize the queue

    for(int i = 0; i < 10; i++) {
        Append(&myque, i);
    }

    QueueElement x;
    while (!IsQueueEmpty(&myque)) {
        Serve(&myque, &x);
        printf("Served: %d\n", x);
    }
    return 0;
}

























