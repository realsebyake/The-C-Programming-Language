#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    return 0.0;
}

int main(int argc, char *argv[]) {
    double op2;
    int i;

    for (i = 1; i < argc; i++) {
        if (isdigit(argv[i][0]))
            push(atof(argv[i]));
        else {
            switch (argv[i][0]) {
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
                push(pop() / op2);
                break;
            }
        }
    }
    printf("%g\n", val[sp-1]);
    return 0;
}

// Ex 5-10: Write the program expr, which evaluates a reverse polish expression from the command line, where each operator or operand is a separate argument. For example: expr 2 3 4 + *
