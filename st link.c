#include<stdio.h>
#include<stdlib.h>

typedef int StackEntry;

// Node structure
typedef struct stackNode {
    StackEntry entry;
    struct stackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

void createStack(Stack *s) {
    s->top = NULL;
}

int isStackEmpty(const Stack *s) {
    return s->top == NULL;
}

// Push
void push(StackEntry item, Stack *s) {
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("--- Stack is Full! ---\n");
        exit(1); // Exit
    }
    newNode->entry = item;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop
void pop(StackEntry *item, Stack *s) {
    if (!isStackEmpty(s)) {
        StackNode *tempNode = s->top;
        *item = s->top->entry;
        s->top = s->top->next;
        free(tempNode);
    } else {
        printf("---Stack is Empty ! ---\n");
        exit(1);
    }
}

int main() {
    Stack mystack;
    createStack(&mystack);

    for(int i = 0; i < 10; i++) {// inserted i is int
        push(i, &mystack);
    }

    StackEntry item;
    while (!isStackEmpty(&mystack)) {
        pop(&item, &mystack);
        printf("Popped item: %d\n", item);// output  is int
    }

    return 0;
}
