#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node* createNode(int number) {
    struct node* node = calloc(1,sizeof(struct node));
    node->value = number;
    return node;
}
struct node* insertValueAfter(int number, struct node* previous) {
    struct node* this = createNode(number);
    if(!previous->next) {
        previous->next = this;
    } else {
        this->next = previous->next;
        previous->next = this;
    }
    return this;
}
void navigate(struct node* node) {
    while(node) {
        printf("%d, ",node->value);
        node = node->next;
    }
    printf("\b\b ");
}
int findValue(struct node* node, int target) {
    int counter = 0;
    while(node) {
        if(node->value==target) {
            return counter;
        }
        node = node->next;
        counter++;
    }
    printf("value not found");
    return -1;
}
int main() {
    struct node* head = createNode(5);
    struct node* tail = head;
    for(int i = 1; i < 10;i+=i) {
        tail = insertValueAfter(i,tail);
    }
    struct node* surprise = insertValueAfter(10, head);
    int posicao = findValue(head,123123);
    printf("%d",posicao);
    return 0;
}