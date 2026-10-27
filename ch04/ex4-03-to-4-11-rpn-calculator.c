#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXLINE 100
#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int myGetLine(char[], int);
int getop(char []);
// int getch(void);
// void ungetch(int);
void push(double);
void ungets(char []);
double pop(void);

int linep = 0;
int bufFull = 0;
int buf = EOF;
// int bufp = 0; (commented out because 4-8 requires single char, same case for BUFSIZE)
int sp = 0;
int lastvar = 0;
char line[MAXLINE];
// char buf[BUFSIZE];
double val[MAXVAL];
double vars[26];
double last = 0.0;

int main() {

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero division\n");
            break;
        case '\n':
            if (sp > 0) {
                last = val[sp-1];
                printf("\t%.8g\n", val[sp-1]);
            }
            break;
        case 'P':
            if (sp > 0)
                printf("Top element: %f\n", val[sp-1]);
            else
                printf("error: stack is empty\n");
            break;
        case 'D':
            if (sp > 0)
                push(val[sp-1]);
            else
                printf("error: stack is empty\n");
            break;
        case 'S':
            if(sp > 1) {
                double temp = val[sp-1];
                val[sp-1] = val[sp-2];
                val[sp-2] = temp;
            }
            else
                printf("error: stack is empty\n");
            break;
        case 'C':
            if (sp > 0)
                sp = 0;
            else
                printf("error: stack is already empty\n");
            break;
        case 'f':
            if (strcmp(s, "sin") == 0)
                push(sin(pop()));
            else if (strcmp(s, "exp") == 0)
                push(exp(pop()));
            else if (strcmp(s, "pow") ==  0) {
                op2 = pop();
                push(pow(pop(), op2));
            } else
                printf("error: unknown function %s\n", s);
            break;
        case 'v':
            lastvar = s[0];
            push(vars[s[0] - 'a']);
            break;
        case '=':
            vars[lastvar - 'a'] = val[sp-2];
            pop();
            break;
        case '@':
            push(last);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void push (double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {

    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* int getop(char s[]) { // Commented out due to 4-11

    int i, c, next, neg;
    neg = 0;

    if (line[linep] == '\0') {
        if (myGetLine(line, MAXLINE) == 0)
            return EOF;
        linep = 0;
    }
    while ((s[0] = c = line[linep++]) == ' '  || c == '\t')
        if (line[linep] == '\0')
            if (myGetLine(line, MAXLINE) == 0)
                return EOF;
    s[1] = '\0';
    if (c == '-') {
        next = line[linep++];
        if (isdigit(next)) {
            linep--;
            i = 1;
            neg = 1;
            c = line[linep++];
        } else {
            linep--;
            return c;
      }
    }
    if (isalpha(c)) {
        i = 0;
        s[i++] = c;
        while (isalpha(s[i++] = c = line[linep++]))
            ;
        s[i-1] = '\0';
        if (c != EOF)
            linep--;
        if (i > 2)
            return 'f';
        else
            return 'v';
    }
    if (c == '@')
        return '@';
    if (!isdigit(c) && c != '.')
        return c;
    if (!neg)
        i = 0;
    s[i++] = c;
    if (isdigit(c))
        while (isdigit(s[i++] = c = line[linep++]))
            ;
    s[i] = '\0';
    if (c != EOF)
        linep--;
    return NUMBER;
} */

int getop(char s[]) {

    int i, c;
    static int leftover = 0;

    while ((s[0] = c = (leftover ? leftover : getchar())) == ' ' || c == '\t')
        leftover = 0;
    leftover = 0;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    s[i++] = c;
    if (isdigit(c))
        while (isdigit(s[i++] = c = getchar()))
            ;
    if (s[i] == '.')
        i++;
    s[i] = '\0';
    if (c != EOF)
        leftover = c;
    return NUMBER;
}

/* int getch(void) {

    int c;

    if (bufFull) {
        bufFull =  0;
        return buf;
    }
    return getchar();
} */

/* void ungetch(int c) {

    if (bufFull)
        printf("ungetch: too many characters\n");
    else {
        buf = c;
        bufFull = 1;
    }
} */

void ungets(char s[]) {

    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    while (i-- > 0)
        line[--linep] = s[i];
}

int myGetLine(char line[], int lim) {

    int c, i;

    for (i = 0; i < lim-1  && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
