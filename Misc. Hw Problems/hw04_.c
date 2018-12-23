#include <stdio.h>

//Rewrite changeltox() to use array style and a for loop.
void changeltox (char *s) {
    while (*s != '\0') {
      if (*s == 'l')
        *s = 'x';
      s++;
    }
  }
