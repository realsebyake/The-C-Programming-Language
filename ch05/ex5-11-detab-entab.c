#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c, pos = 0;
    int tabsize = 8;

    if (argc > 1)
        tabsize = atoi(argv[1]);

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                putchar(' ');
                pos++;
            } while (pos % tabsize != 0);
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}

/*
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        int c, pos = 0, blanks = 0;
        int tabsize = 8;

        if (argc > 1)
            tabsize = atoi(argv[1]);

        while ((c = getchar()) != EOF) {
            if (c == ' ') {
                blanks++;
                pos++;
                if (pos % tabsize == 0) {
                    putchar('\t');
                    blanks = 0;
                }
            } else {
                while (blanks-- > 0)
                    putchar(' ');
                blanks = 0;
                if (c == '\n')
                    pos = 0;
                else
                    pos++;
                putchar(c);
            }
        }
        return 0;
    }
 */
