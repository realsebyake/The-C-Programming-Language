// 1.7 Functions

#include <stdio.h>

int power(int base, int n);

int krMain() {

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power (-3,i));
    return 0;
}

int power(int base, int n) {
    
    int i, p;
    p = 1;

    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

// next 2 functions are for exercise 1-15
int conversionFunction(int fahr) {

    return 5 * (fahr - 32) / 9;
}

int conversionExercise() {

    int i, fahr;
    printf("fahr\tcelsius\n");

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%d\t%d\n", fahr, conversionFunction(fahr));
    }
    return 0;

}

int main() {
//  krMain();
//  conversionExercise();
    return 0;
}

// P.S to those who are confused by int function(parameter-declarations) format, the parameters that go in parentheses are basically the call to be used outside by other functions
// This means that int power can be called in another function (like how int krMain did and called it in printf with power(2,i)).
// Also it doesn't matter where definitions of functions appear, they may be anywhere as the code execution order only matters in int main().