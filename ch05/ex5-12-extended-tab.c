#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int c, pos = 0;
    int tabsize = 8;
    int start = 1;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            start = atoi(argv[i] + 1);
        else if (argv[i][0] == '+')
            tabsize = atoi(argv[i] + 1);
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            pos = 0;
        } else if (c == '\t') {
            do {
                putchar(' ');
                pos++;
            } while ((pos - start + 1) % tabsize != 0);
        } else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}
