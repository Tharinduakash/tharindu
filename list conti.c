#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 10
#define EMPTY 0
#define FULL MAXLIST

typedef enum {FALSE, TRUE} Boolean;
typedef char ListData;
typedef int Position;

typedef struct {
    int count;
    ListData entry[MAXLIST];
} List;

// CreateList
void CreateList(List *l) {
    l->count = 0;
}

// IsListEmpty
Boolean IsListEmpty(const List *l) {
    return (l->count == EMPTY);
}

// IsListFull
Boolean IsListFull(const List *l) {
    return (l->count == FULL);
}

// ListSize
int ListSize(const List *l) {
    return (l->count);
}

// Warning
void Warning(char *message) {
    printf("Warning: %s\n", message);
}

// Error
void Error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

// InsertLast
void InsertLast(ListData x, List *l) {
    if (IsListFull(l)) {
        Warning("Can't insert to a full list");
        exit(1);
    }
    l->entry[l->count++] = x;
}

// InsertList
void InsertList(Position p, ListData x, List *l) {
    if (IsListFull(l))
        Error("Can't insert to a full list");
    else if (p < 0 || p > ListSize(l))
        Error("Position not in the list");
    else {
        for (int i = ListSize(l) - 1; i >= p; i--)
            l->entry[i + 1] = l->entry[i];
        l->entry[p] = x;
        l->count++;
    }
}

// DeleteList
void DeleteList(Position p, ListData *x, List *l) {
    if (IsListEmpty(l))
        Error("Can't delete from a empty list");
    else if (p < 0 || p >= ListSize(l))
        Error("Position not in the list");
    else {
        *x = l->entry[p];
        for (int i = p; i < ListSize(l) - 1; i++)
            l->entry[i] = l->entry[i + 1];
        l->count--;
    }
}

// RetrieveList
void RetrieveList(Position p, ListData *x, List *l) {
    if (IsListEmpty(l))
        Error("Can't retrieve from a empty list");
    else if (p < 0 || p >= ListSize(l))
        Error("Position not in the list");
    else
        *x = l->entry[p];
}

// ReplaceList
void ReplaceList(Position p, ListData x, List *l) {
    if (IsListEmpty(l))
        Error("ACan't replace in a empty list");
    else if (p < 0 || p >= ListSize(l))
        Error("Position not in the list");
    else
        l->entry[p] = x;
}

// TraverseList
void TraverseList(const List *l) {
    for (int i = 0; i < l->count; i++)
        printf("%c ", l->entry[i]);
    printf("\n");
}
int main() {
    List myList;
    CreateList(&myList);

    // Check if the list is empty
    printf("Is the list empty? %s\n", IsListEmpty(&myList) ? "Yes" : "No");

    // Fill the list
    for(char c = 'A'; c < 'A' + MAXLIST; c++) {
        InsertLast(c, &myList);
    }

    // Attempt to insert into a full list to check error handling
    //printf("Attempting to insert into a full list.\n");
    //InsertLast('Z', &myList);
        // This should trigger a warning and exit
        // Since the above InsertLast will exit the program if the list is full,
        // the below code won't be executed. To test the rest, comment out the above InsertLast call.

    // Retrieve an element from the list
    ListData data;
    RetrieveList(5, &data, &myList);
    printf("Element at position 5: %c\n", data);

    // Replace an element in the list
    ReplaceList(5, 'K', &myList);
    printf("After replacing element at position 5 with 'K':\n");
    TraverseList(&myList);

    // Delete an element from the list
    DeleteList(5, &data, &myList);
    printf("After deleting element at position 5 (was 'K'): \n");
    TraverseList(&myList);

    // Insert at a specific position
    InsertList(3, 'Z', &myList);
    printf("After inserting 'Z' at position 3: \n");
    TraverseList(&myList);

    // Final list traversal
    printf("Final list: \n");
    TraverseList(&myList);

    return 0;
}

