// 2x / 3 + 7  = 9 (equation represented in the functions) 
// this is my own example, does not appear in K&R

#include <stdio.h>

void integerEquation() {
      
    int result, x;
    
    x = 0;

    while (x <= 9) {
        result = ((2 * x) / 3) + 7;
        printf("x = %d, result = %d\n", x, result); /* the 2 printfs are just a way to showcase how you can differently write them, 11 being specific, 12 being direct */
        printf("%5d %10d\n", x, result);
        x = x + 1;
    }
}

void floatEquation() {

    float result, x;

    x = 0;

    while (x <= 9.0) {
        result = x * (2.0/3.0) + 7.0;
        printf("x = %f, result = %f\n", x, result);
        printf("%5.0f %10.0f\n", x, result);
        x = x + 1.0;
    }
}

int main() {
    integerEquation();
    floatEquation();
    return 0;
}