#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *previous;
};
struct stack {
    struct node* tail;
};

int dequeue(struct stack *stk) {
    struct node* sTail = stk->tail;
    int returnData = sTail->value;
    stk->tail = sTail->previous;
    free(sTail);
    return returnData;
}
void enqueue(int number, struct stack* stk) {
    struct node* newTail = calloc(1,sizeof(struct node));
    newTail->value = number;
    newTail->previous = stk->tail;
    stk->tail = newTail;
}

void peek(struct stack* stk) {
    printf("%d, ",stk->tail->value);
}
int main() {
    struct stack* chadStack = calloc(1,sizeof(struct stack));
    enqueue(69, chadStack);
    return 0;
}