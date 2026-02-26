// This is from 1.5.#

#include <stdio.h>

    #define IN 1   // defines are needed for unix word counting and ex 1-12
    #define OUT 0 

void krExample() {

    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}

// Exercise 1-6
void firstExercise() {

    int c;

    while ((c = getchar()) != EOF) {
        printf("%d\n", c != EOF);
    }
}

// Exercise 1-7
void secondExercise() {

    printf("%d\n", EOF);
}

//-------------------------------------------------------------------------------------------//

void krCharCounting() {
   
    double nc;    // double precision float point to avoid byte overflow (rare)

    for (nc = 0; getchar() != EOF; ++nc)
        ;                     // semicolon is a null statement since for loops require body contents, semicolon satisfies that requirement
    printf("%.0f\n", nc);
}

//-------------------------------------------------------------------------------------------//

void krLineCounting() {

    int c, nl;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
        ++nl;
  }
  printf("%d\n", nl);
}

// Exercise 1-8
void thirdExercise() {

    int c, nb, nt, nl;
    nb = nt = nl = 0;

    while ((c = getchar()) != EOF) {
    if (c == ' ')
        ++nb;
    if (c == '\t')
        ++nt;
    if (c == '\n')
        ++nl;
    }
    printf("blanks = %d\t tabs = %d\t newlines = %d\n", nb, nt, nl);
}

// Exercise 1-9
void fourthExercise() {

    int c, last;
    last = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && last == ' ')
            ;                                   // same thing as the for loop
        else
        putchar(c);
    last = c;
    }
}

// Exercise 1-10
void fifthExercise() {

    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}

//-------------------------------------------------------------------------------------------//

// Based on a UNIX program, also press CTRL+D after you wrote the few input lines in terminal
void krWordCounting() {

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("nl = %d nw = %d nc = %d\n", nl, nw, nc);

}

void sixthExercise() {

    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\n');
            putchar(c);
        }
        else
            putchar(c);

}
//-------------------------------------------------------------------------------------------//

int main() {
  krExample();
//  firstExercise();
//  secondExercise();
//  krCharCounting();
//  krLineCounting();
//  thirdExercise();
//  fourthExercise();
//  fifthExercise();
//  krWordCounting();
//  sixthExercise();
return 0;
}