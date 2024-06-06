#include <stdio.h>
#include <stdlib.h>

int main() {
    int list[] = {1,3,4,7,9,14,56,65};
    int size = sizeof(list)/sizeof(int);
    int lo = 0;
    int hi = size-1;
    char buf[1024]; //1kb to make sure
    int value;
    do {
        if(!fgets(buf,1024,stdin)) {
            printf("n deu pra escrever n");
            return 1;
        }
        value = atoi(buf);
    } while(value==0);
    while(lo < hi) {
        printf("searching... ");
        int m = lo + (hi-lo)/2;
        if(list[m]==value) {
            printf("value is at position %d", m);
            return 0;
        } else if(list[m]>value) {
            hi = m;
        } else if(list[m]<value) {
            lo = m+1;
        }
    }
    printf("value is not within list");
    return 1;
}
