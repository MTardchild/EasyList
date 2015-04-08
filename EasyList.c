#include <stdio.h>
#include <stdlib.h>
#include "EasyList.h"

void ListPrint (NextPlaceOps *head) {
    NextPlaceOps *current = head;
    int i = 0;

    while (current != NULL) {
        printf("List[%d]: %d \n", i, current->value);
        current = current->next;
        i++;
    }
}

void ListPushEnd (NextPlaceOps *head, int value) {
    NextPlaceOps *current = head;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(NextPlaceOps));
    current->next->value = value;
    current->next->next = NULL;
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

int main () {
    NextPlaceOps *head = NULL;
    head = malloc(sizeof(NextPlaceOps));

    if (head == NULL) {
        return 1;
    }

    printf("// Initialized standard list with values 1 and 2 //\n");
    head->value = 1;
    head->next = malloc(sizeof(NextPlaceOps));
    head->next->value = 2;
    head->next->next = NULL;

    printf("\n // Push at end, value 5// \n");
    ListPushEnd(head, 5);
    ListPrint(head);

    NextPlaceOps **HeadPointer = &head;
    printf("\n// Push to start, value 12 // \n");

    ListPushStart(HeadPointer, 12);
    ListPrint(head);

    printf("\n// Pop at Start and End // \n");
    ListPopStart(HeadPointer);
    ListPopEnd(head);
    ListPrint(head);

    printf("\n// Pop at Index 1 // \n");
    ListPopAtIndex(HeadPointer, 1);
    ListPrint(head);

    printf("\n// Push at Index 2 // \n");
    ListPushAtIndex(HeadPointer, 5, 2);
    ListPrint(head);

    printf("\n// Push at Index 1 // \n");
    ListPushAtIndex(HeadPointer, 5, 1);
    ListPrint(head);

    return 0;
}
