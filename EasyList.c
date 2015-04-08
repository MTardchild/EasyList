#include <stdio.h>
#include <stdlib.h>
#include "EasyList.h"

#define PLACES 5

void ListPrint (NextPlaceOps *head) {
    NextPlaceOps *current = head;

    while (current != NULL) {
        printf("Iterate List: %d \n", current->value);
        current = current->next;
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

int main ()
{
    NextPlaceOps *head = NULL;
    head = malloc(sizeof(NextPlaceOps));

    if (head == NULL) {
        return 1;
    }

    head->value = 1;
    head->next = malloc(sizeof(NextPlaceOps));
    head->next->value = 2;
    head->next->next = NULL;

    ListPushEnd(head, 5);
    ListPrint(head);

    NextPlaceOps **HeadPointer = &head;
    printf("//////////////// \n\n");

    ListPushStart(HeadPointer, 12);
    ListPrint(head);

    return 0;
}
