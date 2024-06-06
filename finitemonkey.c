#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char buf[1024];
    int value;
    do {
        if(!fgets(buf,1024,stdin)) {
            printf("error");
            return 1;
        }
        value = atoi(buf);
    } while(value==0);
    char text[value];
    for(int i = 0; i <= value; i++) {
        text[i] = (rand() % 25) + 'A';
    }
    fptr = fopen("uga buga.txt", "a");
    fprintf(fptr, text);
    fclose(fptr);
    return 0;
}
