#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char array[] = "teste";

    char *harray =  "teste";

    printf("stack: %p\n", (void *)&array);
    printf("heap: %p\n", (void *)harray);
}
