// 1.10 Exercises

#include <stdio.h>

#define TABSIZE 8 // needed for ex 1-20 and 1-21
#define MAXLINE 1000 // needed for ex 1-22
#define FOLD 40 // needed for ex 1-22

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

int main() {

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
    } else if (c == '\n') {
        line[i+1] = '\0';
        printf("%s", line);
        i = 0;
        lastspace = -1;
    } else {
        ++i;
    }
}


return 0;
}

