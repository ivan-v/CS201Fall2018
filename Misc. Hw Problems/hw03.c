#include <stdio.h>

void escape(char s[], char t[]) {
	int i, j = i = 0;

	while (t[i] != '\0') {
		switch(t[i]) {
			case '\t':
				s[j] = '\\';
				++j;
				s[j] = '\t';
				break;

			case '\n':
				s[j] = '\\';
				++j;
				s[j] = '\n';
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

void unescape(char s[], char t[]) {
	int i, j = i = 0;

	while (t[i]) {
        switch (t[i]) {
	        case '\\':
	            switch( t[++i] ) {
	            	case 'n':
	                	s[j] = '\n';
	                	break;
	                
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

