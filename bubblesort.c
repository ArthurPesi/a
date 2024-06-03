#include <stdio.h>

int main() {
    int list[] = {13,7,3,19,89,45,1,99999,123,96,2,9,9999,44,190,69,420};
    int size = sizeof(list)/sizeof(int);
    for(int i = 0;i<size;i++) {
        for(int j = 0;j<size-i-1;j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    for(int k = 0; k<size;k++) {
        printf("%d, ",list[k]);
    }
    printf("\b\b ");
    return 0;
}