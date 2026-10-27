// 1.6 Arrays

#include <stdio.h>

void krArray() {

    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

}

void histogramOne() {

    #define IN 1
    #define OUT 0

    int c, i, j, length, state;
    state = OUT;
    length = 0;
    int wordlen[20];

    for (i = 0; i < 20; ++i)
        wordlen[i] = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            ++wordlen[length];
            length = 0;
        }
        else {
           ++length;
        }

    for (i = 0; i < 20; ++i) {
        printf("%d: ", i);
    for (j = 0; j < wordlen[i]; ++j)
        printf("*");
    printf("\n");
    } 
}

void  histogramTwo() {

    int c, i, j;
    int wordfreq[128];

    for (i = 0; i < 128; ++i)
        wordfreq[i] = 0;

    while ((c = getchar()) != EOF)
        ++wordfreq[c];

    for (i = 0; i < 128; i++)
        if (wordfreq[i] > 0) {
            printf("%c: ", i);
            for (j = 0; j < wordfreq[i]; ++j)
                printf("*");
        printf("\n");
        }
    
}

int main() {

//  krArray();
//  histogramOne();
    histogramTwo();
    return 0;
}