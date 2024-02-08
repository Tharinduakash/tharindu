#include <stdio.h>
#include <stdlib.h>

typedef char ListData;
typedef int Position;

typedef struct ListNode {
    ListData data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    int count;
} List;

// CreateList
void CreateList(List *l) {
    l->head = NULL;
    l->count = 0;
}

// IsListEmpty
int IsListEmpty(const List *l) {
    return (l->head == NULL);
}

// ListSize
int ListSize(const List *l) {
    return l->count;
}

// Error
void Error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

// InsertLast
void InsertLast(ListData x, List *l) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        Error("Memory allocation failed");
    }
    newNode->data =x;
    newNode->next =NULL;

    if (IsListEmpty(l)) {
        l->head = newNode;
    } else {
        ListNode *current= l->head;
        while (current->next!= NULL) {
            current= current->next;
        }
        current->next = newNode;
    }
    l->count++;
}

// TraverseList
void TraverseList(const List *l) {
    ListNode *current = l->head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

// InsertList - Inserts at a given position (0-based)
void InsertList(Position p, ListData x, List *l) {
    if (p< 0 || p> l->count) {
        Error("Position out of bounds");
    }

    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        Error("Memory allocation failed");
    }
    newNode->data = x;

    if (p == 0) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
        ListNode *current = l->head;
        for (int i=0; i< p-1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    l->count++;
}

// DeleteList - Deletes an element at a given position (0-based)
void DeleteList(Position p, ListData *x, List *l) {
    if (IsListEmpty(l)) {
        Error("Can't delete from an empty list");
    }
    if (p<0 || p>= l->count) {
        Error("Position out of bounds");
    }

    ListNode *temp;
    if (p == 0) {
        temp = l->head;
        *x = temp->data;
        l->head = l->head->next;
    } else {
        ListNode *current = l->head;
        for (int i=0; i<p-1; i++) {
            current = current->next;
        }
        temp = current->next;
        *x = temp->data;
        current->next = temp->next;
    }
    free(temp);
    l->count--;
}

int main() {
    List myList;
    CreateList(&myList);

    // Fill the list
    for (char c='A'; c<'A'+5; c++) {
        InsertLast(c,&myList);
    }
    printf("List after inserting A to E at the end:\n");
    TraverseList(&myList);

    // Insert at a specific position
    InsertList(2,'Z',&myList);
    printf("After inserting 'Z' at position 2: \n");
    TraverseList(&myList);

    // Delete an element from the list
    ListData data;
    DeleteList(2,&data,&myList);
    printf("After deleting element at position 2 (was 'Z'): \n");
    TraverseList(&myList);

    return 0;
}
