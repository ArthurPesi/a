#include <stdio.h>
#include <stdlib.h>
struct arraylist {
    int size;
    int head;
    int array[];
};

struct arraylist *initializeArraylist(int arraySize) {
    struct arraylist *list = malloc(sizeof(struct arraylist) + (sizeof(int) * arraySize));
    list->head = -1;
    list->size = arraySize;
    return list;
}

int pop(struct arraylist *stack) {
    if(stack->head >= 0) {
        stack->head--;
        return stack->array[stack->head+1];
    }
    return -1;
}

struct arraylist *push(struct arraylist *stack, int value) {
    stack->head++;
    if(stack->head >= stack->size) {
        struct arraylist *new;
        new = initializeArraylist(stack->size*2);
        for(int i = 0; i < stack->size;i++) {
            push(new,stack->array[i]);
        }
        free(stack);
        new->head++;
        new->array[new->head] = value;
        return new;
    }
    stack->array[stack->head] = value;
    return stack;
}

int main() {
    struct arraylist *stack;
    stack = initializeArraylist(4);
    for(int i = 0; i < 200; i++) {
        stack = push(stack, i);
    }
    int ueia = 0;
    for(int j = 0; j < 20; j++) {
        ueia = pop(stack);
    }
    printf("%d",ueia);
    return 0;
}