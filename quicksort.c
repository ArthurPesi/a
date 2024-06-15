#include <stdio.h>

void quicksort(int left, int right, int *list) {
    if(left>=right) {
        return;
    }
    if(left+1==right) {
        if(list[left]>list[right]) {
            int tmp = list[left];
            list[left] = list[right];
            list[right] = tmp;
        }
        return;
    }
    int p = list[right];
    int control = left;
    for(int i = left;i<=right;i++) {
        if(list[i]<p) {
            int tmp_ = list[i];
            list[i] = list[control];
            list[control] = tmp_;
            control++;
        }
        //compara com o pivo e bota pros lado
    }
    list[right] = list[control];
    list[control] = p;
    quicksort(left,control-1,list);
    quicksort(control+1,right,list);
}

int main() {
    int list[] = {1,70,3,2,5,69,420,6,8,4,3434,21,3,121,2323,111,7,44,78,17,55,34,6,100};
    int right = (sizeof(list)/sizeof(int))-1;
    quicksort(0, right,list);
    for(int i = 0; i<sizeof(list)/sizeof(int);i++) {
        printf("%d, ",list[i]);
    }
    printf("\b\b \n");
 
    return 0;
}