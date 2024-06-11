#include <stdio.h>
#include <windows.h>

int main() {
    char chars[] = {'|','/','-','\\'};
    unsigned int i = 0;
    while(i < 65530) {
        printf("%c\r",chars[i % sizeof(chars)]);
        Sleep(100);
        i++;
    }
    return 0;
}
