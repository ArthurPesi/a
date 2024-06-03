#include <stdio.h>
#include <stdlib.h>

int main() {
    int list[] = {12, 4, 2, 6, 8, 10};
    int size = sizeof(list)/sizeof(int);
    char buf[1024];
    int value;
    do {
        if(!fgets(buf,1024,stdin)) {
            printf("n deu pra escrever n");
            return 1;
        }
        value = atoi(buf);
    } while(value==0);
    for(int i = 0;i < size;i++) {
        if(value==list[i]) {
            printf("value is at position: %d", i);
            return 0;
        }
    }
    printf("value is not within list");
    return 1;
}