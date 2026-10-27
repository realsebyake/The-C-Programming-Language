#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int myGetline(char *, int);

int main(int argc, char *argv[]) {

    int N = 10;
    if (argc > 1)
        N = atoi(argv[1] + 1);

    char line[MAXLINE];
    char buffer[N][MAXLINE];
    int next = 0, count = 0;
    int i;

    while (myGetline(line, MAXLINE) > 0) {
        strcpy(buffer[next], line);
        next = (next + 1) % N;
        count++;
    }

    if (count <= N) {
        for (i = 0; i < count; i++)
            printf("%s", buffer[i]);
    } else {
        for (i = 0; i < N; i++)
            printf("%s", buffer[(next + i) % N]);
    }

    return 0;
}

int myGetline(char *s, int lim) {
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}
