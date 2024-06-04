#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
struct queue {
    struct node* head;
    struct node* tail;
    int length;
};

int dequeue(struct queue *myQueue) {
    struct node* queueHead = myQueue->head;
    int returnData = queueHead->value;
    myQueue->head = queueHead->next;
    free(queueHead);
    return returnData;
}
void enqueue(int number, struct queue* myQueue) {
    struct node* newTail = calloc(1,sizeof(struct node));
    newTail->value = number;
    if(myQueue->tail) {
        myQueue->tail->next = newTail;
    } else {
        myQueue->head = newTail;
    }
    myQueue->tail = newTail;
}

int peek(struct queue* q) {
    return q->head->value;
}
int main() {
    struct queue* myAwesomeQueue = calloc(1,sizeof(struct node));
    enqueue(2,myAwesomeQueue);
    enqueue(69, myAwesomeQueue);
    printf("%d, ",peek(myAwesomeQueue));
    printf("%d, ",dequeue(myAwesomeQueue));
    printf("%d", peek(myAwesomeQueue));
    return 0;
}