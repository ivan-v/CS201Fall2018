#include <stdio.h>

int main() {
    int c = getchar();
    while (c != EOF) {
        if (c == ' ') 
            putchar('\n');
        else
            putchar(c);
        c = getchar();
    }
}