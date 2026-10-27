#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y) {

return (x & ~(~(~0U << n) << (p + 1 - n))) | ((y &  ~(~0U << n)) << (p + 1 -n)); 

}   

unsigned getbits(unsigned x, int p, int n) {

return  (~(~0U << n) & (x >> (p + 1 - n)));
    
}

unsigned invert(unsigned x, int p, int n) {

return ((~(~0U << n) << p) ^ x);

}

unsigned rightrot(unsigned x, int n) {

return (x & ~(~0U << n)) << (sizeof(unsigned) * 8 - n) | (x >> n);

}

int main() {

int x = 14;  // 00001110
int y = 7;   // 00000111
int p = 4;   // 00000010
int n = 2;   // 00000010


printf("%u\n", setbits(x, p, n, y));
printf("%u\n", getbits(x, p, n));
printf("%u\n", invert(x, p, n));
printf("%u\n", rightrot(x, n));
return 0;
}

/* space to visualize bits




    






*/
