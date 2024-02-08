#include<stdio.h>
#include<stdlib.h>

#define MAXSTACK 10

typedef int stackEntry;

typedef struct {
    int top;
    stackEntry entry[MAXSTACK];
} Stack;

// CreateStack
void createStack(Stack *s){
    s->top = -1;
}

// IsStackEmpty
typedef enum {FALSE, TRUE} Boolean;

Boolean isStackEmpty(const Stack *s){
    return (s->top == -1);
}

// IsStackFull
Boolean isStackFull(const Stack *s){
    return (s->top == MAXSTACK - 1);
}

// Push
void push(stackEntry item, Stack *s){
    if(!isStackFull(s))
        s->entry[++s->top] = item;
    else{
        printf("---Stack is Full !!! ---\n");
        exit(1); // Program exit
    }
}

// Pop
void pop(stackEntry *item, Stack *s){
    if(!isStackEmpty(s))
        *item = s->entry[s->top--];
    else{
        printf("---Stack is Empty !!! ---\n");
        exit(1); // Program exit
    }
}

int main(){

    Stack mystack;
    createStack(&mystack);

    for(int i = 0; i < 10; i++) // inserted i is int
        push(i, &mystack);

    stackEntry item;
    while (!isStackEmpty(&mystack)) {
        pop(&item, &mystack);
        printf("Popped item: %d\n", item);// output  is int
    }

    return 0;
}
