#include <stdio.h>

int main() {
  int c, empty_string = "";
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
        if (empty_string == 0) { 
            empty_string = 1;
            putchar(c);
        }
    } else {
        empty_string = 0;
        putchar(c);
    }
  }
}