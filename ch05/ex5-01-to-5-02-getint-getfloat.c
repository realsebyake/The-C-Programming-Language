#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getfloat(double *);

int main() {

    double x;
    getfloat(&x);
    printf("%f\n", x);

return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1: 1;
    if (c == '+' || c == '-') {
        int prev = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(prev);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(double *pn) {

    double val, power;
    int i, c, sign, exp, expsign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1: 1;
    if (c == '+' || c == '-') {
        int prev = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(prev);
            return 0;
        }
    }
    for (val = 0.0; isdigit(c); c = getch())
        val = 10.0 * val + (c - '0');
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        val = 10.0 * val + (c - '0');
        power *= 10.0;
    }
    if (c != EOF)
        ungetch(c);
    *pn = sign * val / power;

   return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
