// 1.10 Exercises

#include <stdio.h>

#define TABSIZE 8 // needed for ex 1-20 and 1-21
#define MAXLINE 1000 // needed for ex 1-22
#define FOLD 40 // needed for ex 1-22

#define NORMAL 0 // all below are ex 1-23 / 1-24
#define IN_STRING 1
#define IN_BLOCK_COMMENT 2
#define IN_LINE_COMMENT 3
#define IN_CHAR 4

#define NORMAL_SYNTAX 5 // all below are ex 1-24

// Ex 1-20

/* int main() {

    int col, spaces, c, i;
    col = spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            col = 0;
        }
        else if (c == '\t') {
            spaces = TABSIZE - (col % TABSIZE);
            for (i = 0; i < spaces; ++i) {
                putchar(' ');
                ++col;
            }
        }
        else {
        putchar(c);
        ++col;
        }
    }
return 0;
} */

// Ex 1-21

/* int main() {

    int col, spaces, c, i;
    col = spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            for (i = 0; i < spaces; ++i) {
                putchar(' ');
            }
            spaces = 0;
            putchar('\n');
            col = 0;
        }
        else if (c == ' ') {
            ++spaces;
            ++col;
            if (col % TABSIZE == 0) {
                printf("\t");
                spaces = 0;
            }
        }
        else {
            for (i = 0; i < spaces; ++i)
                putchar(' ');
            spaces = 0;
            putchar(c);
            ++col;
}
    }
return 0;
} */

// Ex 1-22

/* int main() {

    char line[MAXLINE];
    int c, i, j, k, lastspace;
    i = 0;
    lastspace = -1; // -1 initial value for no space seen yet

    while ((c = getchar()) != EOF) {
    line[i] = c;
    if (c == ' ')
        lastspace = i;
    if (i >= FOLD) {
        if (lastspace == -1)
            lastspace = i;
        for (j = 0; j < lastspace; ++j)
            putchar(line[j]);
        putchar('\n');
        for (k = 0; k < i - lastspace; ++k)
            line[k] = line[lastspace + 1 + k];
        i = i - lastspace - 1;
        lastspace = -1;
    }
    else if (c == '\n') {
        line[i+1] = '\0';
        printf("%s", line);
        i = 0;
        lastspace = -1;
    }
    else {
        ++i;
    }
    }

return 0;
} */

// Ex 1-23

/* int main() {

int c, next;
int state = NORMAL;

    while ((c = getchar()) != EOF) {
        if (state == NORMAL) {
            if (c == '/') {
                next = getchar();
                if (next == '/') {
                    state = IN_LINE_COMMENT;
                }
                else if (next == '*') {
                    state = IN_BLOCK_COMMENT;
                }
                else {
                    putchar('/');
                    ungetc(next, stdin);
                }
            }
            else if (c == '"') {
                state = IN_STRING;
                putchar(c);
            }
            else if (c == '\'') {
                state = IN_CHAR;
                putchar(c);
            }
            else {
                putchar(c); 
            }
        }
        else if (state == IN_LINE_COMMENT) {
            if (c == '\n') {
                state = NORMAL;
                putchar('\n');
            }
            else { // empty because it shouldn't do anything
            }
        }
        else if (state == IN_BLOCK_COMMENT) {
            if (c == '*') {
                next = getchar();
                if (next == '/') {
                    state = NORMAL;
                    putchar(' ');
                }
                else {
                    ungetc(next, stdin);
                }
            }
        }
        else if (state == IN_STRING) {
            if (c == '"') {
                state = NORMAL;
                putchar(c);
            }
            else if (c == '\\') {
                getchar();
            }
            else {
                putchar(c);
            }
        }
        else if (state == IN_CHAR) {
            if (c == '\'') {
                state = NORMAL;
                putchar(c);
            }
            else if (c == '\\') {
                getchar();
            }
            else {
                putchar(c);
            }
        }
    }
return 0;
} */

// Ex 1-24

int main() {

int parens = 0, brackets = 0, braces = 0;
int c, next;
int state = NORMAL_SYNTAX;

    while ((c = getchar()) != EOF) {
        if (state == NORMAL_SYNTAX) {
            if (c == '/') {
                next = getchar();
                if (next == '/') {
                    state = IN_LINE_COMMENT;
                }
                else if (next == '*') {
                    state = IN_BLOCK_COMMENT;
                }
                else {
                    ungetc(next, stdin);
                }
            }
            else if (c == '"') {
                state = IN_STRING;
            }
            else if (c == '\'') {
                state = IN_CHAR;
            }
            else {
                if (c == '(') {
                    ++parens;
                }
                else if (c == ')') {
                    --parens;
                }
                else if (c == '{') {
                    ++braces;
                }
                else if (c == '}') {
                    --braces;
                }
                else if (c == '[') {
                    ++brackets;
                }
                else if (c == ']') {
                    --brackets;
                }
            }
        }
        else if (state == IN_LINE_COMMENT) {
            if (c == '\n') {
                state = NORMAL_SYNTAX;
            }
            else {
            }
        }
        else if (state == IN_BLOCK_COMMENT) {
            if (c == '*') {
                next = getchar();
                if (next == '/') {
                    state = NORMAL_SYNTAX;
                }
                else {
                    ungetc(next, stdin);
                }
            }
        }
        else if (state == IN_STRING) {
            if (c == '"') {
                state = NORMAL_SYNTAX;
            }
            else if (c == '\\') {
                getchar();
            }
            else {
            }
        }
        else if (state == IN_CHAR) {
            if (c == '\'') {
                state = NORMAL_SYNTAX;
            }
            else if (c == '\\') {
                getchar();
            }
            else {
            }
        }
    }

    if (parens != 0) {
        printf("ERROR: Unbalanced parentheses\n");
    }
    if (braces != 0) {
        printf("ERROR: Unbalanced braces\n");
    }
    if (brackets != 0) {
        printf("ERROR: Unbalanced brackets\n");
    }


return 0;
}
