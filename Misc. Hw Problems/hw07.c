#include <stdio.h>

void detab(char s[], char t[]) {
	int i, j = i = 0;

	while (t[i] != '\0') {
		switch(t[i]) {

			case '\t':
				s[j] = '\\';
				++j;
				s[j] = '\t';
				break;

			default: 
				s[j] = t[i];
				break;
		}
		++i;
		++j;
	}
	s[j]='\0';
}

void entab(char s[], char t[]) {
	int i, j = i = 0;

	while (t[i]) {
        switch (t[i]) {
	        case '\\':
	            switch( t[++i] ) {

	            	case 't':
	                	s[j] = '\t';
	                	break;

					default: 
						s[j++] = '\\';
	                	s[j] = t[i];
				}
				break;

			default: s[j] = t[i];
		}
		++i;
		++j;
	}
	s[j] = t[i];
}


int tab(char const* arg) {
    return strcmp(arg, "-en") == 0 ? entab(stdin, stdout)
        :  strcmp(arg, "-de") == 0 ? detab(stdin, stdout);
}