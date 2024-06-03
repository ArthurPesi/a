#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input;
    const char word[] = "cleiten";
    char guessed[] = {'_','_','_','_','_','_','_','\0'};
    int lives = 5;
    while(lives>0) {
        int counter = 0;
        input = getchar();
        if(input != '\n') {
            for(int i = 0; i < sizeof(word);i++) {
                if(input == word[i]) {
                    guessed[i] = input;
                    counter++;
                }
            }
            if(counter==0) {
                lives--;
            }
            printf("\x1b[1F");
            printf("lives: %d %s     -> ",lives,guessed);
            if(strcmp(guessed,word)==0) {
                printf("parabens");
                return 0;
            }
        }
    }
    printf("loser");
    return 0;
}