#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int list[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1};
    int size = sizeof(list)/sizeof(int);
    char buf[1024];
    int srt;
    int i = 0;
    srt = (int)sqrt((double)size);
    for(i;i<size;i+=srt) {
        if(list[i]) {
            break;
        }
    }
    for(int j = i-srt;j<=i;j++) {
        if(list[j]) {
            printf("%d",j);
            return 0;
        }
    }
    return 1;
}