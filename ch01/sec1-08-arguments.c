// 1.8 Arguments - Call by Value

#include <stdio.h>

int power(int base, int n) {
    
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

// other than the function above, rest were pasted from Functions to showcase functionality

int krMain() {

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power (-3,i));
    return 0;
}

int main() {
    krMain();
    return 0;
}