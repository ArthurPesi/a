#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORWARD 1
#define BACKWARDS -1

int findnumeral(char *origin) {
    char three[4], four[5], five[6];
    strncpy(three, origin, 3);
    strncpy(four, origin, 4);
    strncpy(five, origin, 5);
    three[3] = '\0';
    four[4] = '\0';
    five[5] = '\0';
    char *numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 10; i++) {
        if(strcmp(three, numbers[i]) == 0 || strcmp(four, numbers[i]) == 0 || strcmp(five, numbers[i]) == 0) {
            return i;
        }
    } 
    return 0;
}

int lookfornumber(char *line, int i, int step, int endpoint) {
    int result;
    while (i != endpoint) {
        if (isdigit(line[i])) {
            return line[i];
        }
        if ((result = findnumeral(&line[i]))) {
            return result + '0';
        }
        i += step;
    }
    printf("no numbers found.");
    return -1;
}

int main() {
    char line[1024], *result;
    FILE *input = fopen("input", "r");
    if (input == NULL) {
        printf("not able to read file");
        return 1;
    }
    int sum = 0;
    while ((result = fgets(line, sizeof(line), input)) != NULL) {
        int size = (int)strlen(result);
        char first, last;

        first = lookfornumber(result, 0, FORWARD, size);
        last = lookfornumber(result, size, BACKWARDS, -1);

        char combination[] = {first, last, '\0'};
        sum += atoi(combination);
    }
    printf("%d\n", sum);
    fclose(input);
}
