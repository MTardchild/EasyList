typedef struct node {
    int value;
    struct node *next;
} NextPlaceOps;

int main();
void ListPrint (NextPlaceOps*);

void ListPushStart (NextPlaceOps **head, int val);
void ListPushEnd (NextPlaceOps*, int);

void ListPopStart (NextPlaceOps **head);
void ListPopEnd (NextPlaceOps *head);

void ListPopAtIndex (NextPlaceOps **head, int index);
void ListPushAtIndex (NextPlaceOps **head, int value, int index);
