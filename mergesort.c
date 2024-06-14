#include <stdio.h>
#include <stdlib.h>

void mergeSort(int left, int middle, int right, int *list) {
    if(left >= right) {
        return;
    }
    int size1 = middle+1-left;
    int size2 = right-middle;
    int *list1 = malloc(sizeof(int)*(size1));
    int *list2 = malloc(sizeof(int)*(size2));
    int _mid1 = left + (middle-left)/2;
    int _mid2 = middle+1 + (right-(middle+1))/2;
    mergeSort(left,_mid1,middle, list);
    mergeSort(middle+1,_mid2,right, list);
    for(int loop1 = left;loop1<left+size1;loop1++) {
        list1[loop1-left] = list[loop1];
    }
    for(int loop2 = middle+1;loop2<middle+1+size2;loop2++) {
        list2[loop2-(middle+1)] = list[loop2];
    }
    int i = left;//
    int hold;
    int one = 0;
    int two = 0;
    for(i;i<right && one<size1 && two<size2;i++) {//5,10
        if(list1[one]<list2[two]) {//32,45
            hold = list2[two];
            list[i] = list1[one];
            one++;
        } else {
            hold = list1[one];
            list[i] = list2[two];
            two++;
        }
    }
    list[i]=hold;
    i++;
    for(one;one<size1 && i < right;one++) {
        list[i] = list1[one];
        i++;
    }
    for(two;two<size2 && i < right;two++) {
        list[i] = list2[two];
    }
    free(list1);
    free(list2);
}

int main() {
    int list[] = {10,5,45,32,3,5,78,4};
    int right = (sizeof(list)/sizeof(int))-1;
    int middle = (right)/2;
    mergeSort(0,middle, right, list);
    for(int i = 0; i<=right;i++) {
        printf("%d, ",list[i]);
    }
    printf("\b\b \n");
    return 0;
}
