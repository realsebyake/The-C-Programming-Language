#include <stdio.h>

// This includes examples of For loop and symbolic constant (that being #define)
// For loop structure: for (<initialization>; <condition>; <update>)

void firstExample() {

    int fahr;

        for (fahr = 0; fahr <= 300; fahr = fahr + 20)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void secondExample() {
  
    int fahr;
    #define LOWER 0
    #define UPPER 300
    #define STEP 20

        for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

}

void exerciseOne() {

    int fahr;

        for (fahr = 300; fahr > 0; fahr = fahr - 20)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

int main() {
    firstExample();
    secondExample();
    exerciseOne();
    return 0;
}