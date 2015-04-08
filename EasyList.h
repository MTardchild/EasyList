typedef struct node {
    int value;
    struct node *next;
} NextPlaceOps;

int main();
void ListPrint (NextPlaceOps*);
void ListPushEnd (NextPlaceOps*, int);
void ListPushStart (NextPlaceOps **head, int val);
