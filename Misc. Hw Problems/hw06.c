#include <stdio.h>
#include<stdlib.h>
#include<string.h>


void mystrncpy(char *s, char *t, int n) {
    while (*t && n-- > 0) {
        *s++ = *t++;
    }
    while (mystrnlen(s) - n -- > 0) {
        *s++;
    }
    *s = '\0';
}