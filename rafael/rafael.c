#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *options() {
    char *values[] = {"muuu.txt", "gatomaconha.txt","MEUAMIGO.txt","miranha.txt","ohomicoelho.txt","sobrinhotadecelta.txt","THEDANGER.txt"};
    printf("1 - vaquinha mu mu\n");
    printf("2 - gato maconha\n");
    printf("3 - sonicao da massa\n");
    printf("4 - miranha\n");
    printf("5 - wallace e gromit\n");
    printf("6 - navezona do pai\n");
    char buf[1024];
    int value;
    do {
        if(!fgets(buf,1024,stdin)) {
            printf("n deu pra escrever n");
        }
        value = atoi(buf);
    } while(value==0);
    if(values[value-1]) {
        return values[value-1];
    }
}

int main() {
    char *fileName = options();
    FILE *fptr;
    fptr = fopen(fileName,"r");
    printf("%s\n",fileName);
    char c;
    do {
        c = fgetc(fptr);
        printf("%c",c);
    } while(c!=EOF);
    fclose(fptr);
    return 0;
}
