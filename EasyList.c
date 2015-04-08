#include <stdio.h>
#include <stdlib.h>
#include "EasyList.h"

void ListPrint (NextPlaceOps *head) {
    NextPlaceOps *Current = head;
    int i = 0;

    while (Current != NULL) {
        printf("List[%d]: %d \n", i, Current->value);
        Current = Current->next;
        i++;
    }
}

void ListPushEnd (NextPlaceOps *head, int value) {
    NextPlaceOps *Current = head;

    while (Current->next != NULL) {
        Current = Current->next;
    }
    Current->next = malloc(sizeof(NextPlaceOps));
    Current->next->value = value;
    Current->next->next = NULL;
}

void ListPushStart (NextPlaceOps **head, int val) {
    NextPlaceOps *NewItem = malloc(sizeof(NextPlaceOps));
    NewItem->value = val;
    NewItem->next = *head;

    *head = NewItem;
}

void ListPopStart (NextPlaceOps **head) {
    if (*head == NULL) {
        return;
    }
    NextPlaceOps *NextItemStore = (*head)->next;
    free(*head);
    *head = NextItemStore;
}

void ListPopEnd (NextPlaceOps *head) {
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    NextPlaceOps *Current = head;
    NextPlaceOps *NextItem = head->next;

    while (NextItem->next != NULL) {
        Current = Current->next;
        NextItem = NextItem->next;
    }
    free(NextItem);
    Current->next = NULL;

}

void ListPopAtIndex (NextPlaceOps **head, int index) {
    if (index == 0) {
        ListPopStart(head);
        return;
    }

    NextPlaceOps *Current = *head;
    NextPlaceOps *NextItem = (*head)->next;
    int i;

    for (i = 0; i < index-1; i++) {
        Current = Current->next;
        NextItem = NextItem->next;
    }
    Current->next = NextItem->next;

    free(NextItem);
}

void ListPushAtIndex (NextPlaceOps **head, int value, int index) {
    if (index == 0) {
        ListPushStart(head, value);
        return;
    }
    NextPlaceOps *NewItem = malloc(sizeof(NextPlaceOps));
    NewItem->value = value;

    NextPlaceOps *Current = *head;
    NextPlaceOps *NextItem = (*head)->next;

    int i;

    for (i = 0; i < index-1; i++) {
        if (Current->next == NULL) {
            printf("Tried to push, but index is out of bounds.\n");
            return;
        }
        Current = Current->next;
        NextItem = NextItem->next;
    }
    NewItem->next = NextItem;
    Current->next = NewItem;
}

void ListPopFirstItemAtValue (NextPlaceOps **headPoint, NextPlaceOps *head, int value) {
    NextPlaceOps *Current = head;
    int i = 0;

    while (Current != NULL) {
        if (Current->value == value) {
            ListPopAtIndex(headPoint, i);
            return;
        }
        Current = Current->next;
        i++;
    }
}

int main () {
    NextPlaceOps *Head = NULL;
    Head = malloc(sizeof(NextPlaceOps));

    if (Head == NULL) {
        return 1;
    }

    printf("// Initialized standard list with values 1 and 2 //");
    Head->value = 1;
    Head->next = malloc(sizeof(NextPlaceOps));
    Head->next->value = 2;
    Head->next->next = NULL;

    printf("\n// Push at end, value 5// \n");
    ListPushEnd(Head, 5);
    ListPrint(Head);

    NextPlaceOps **HeadPointer = &Head;
    printf("\n// Push at start, value 12 // \n");

    ListPushStart(HeadPointer, 12);
    ListPrint(Head);

    printf("\n// Pop at Start and End // \n");
    ListPopStart(HeadPointer);
    ListPopEnd(Head);
    ListPrint(Head);

    printf("\n// Pop at Index 1 // \n");
    ListPopAtIndex(HeadPointer, 1);
    ListPrint(Head);

    printf("\n// Push at Index 2, value 5 // \n");
    ListPushAtIndex(HeadPointer, 5, 2);
    ListPrint(Head);

    printf("\n// Push at Index 1 and 2, value 5 // \n");
    ListPushAtIndex(HeadPointer, 5, 1);
    ListPushAtIndex(HeadPointer, 5, 2);
    ListPrint(Head);

    printf("\n// Pop first item with value 5 // \n");
    ListPopFirstItemAtValue(HeadPointer, Head, 5);
    ListPrint(Head);

    return 0;
}
