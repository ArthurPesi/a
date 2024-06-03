#include <stdio.h>
#include <string.h>

int findNumber(int counter,char input[]) {
    int number = 0;
    while(input[counter] !=43 && input[counter]!='\0') {
        // printf("%d\n",numbers[counter]);
       number = number * 10;
        number += input[counter];
        number -= '0';
        counter++;
    }
    if(input[counter]=='\0') {
        return number;
    }
    return number + findNumber(counter+1, input);
}

int main() {
    char numbers[50];
    if(fgets(numbers,50,stdin)) {
        numbers[strcspn(numbers,"\n")] = 0;
    }
    int counter = 0;
    int sum = findNumber(counter,numbers);
    printf("%d",sum);
    return 0;
}
