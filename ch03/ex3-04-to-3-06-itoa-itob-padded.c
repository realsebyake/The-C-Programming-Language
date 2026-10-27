#include <stdio.h>
#include <string.h>

// This file includes exercises 3: 4-6. Really good piece of practice code not gonna lie

void reverse(char s[]) {

    int i, j;
    char temp;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void  itoa(int n, char s[]) {
    
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = (n < 0 ? -(n % 10) : n % 10) + '0';
    } while ((n /= 10) != 0 );
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s); 
}

void  itob(int n, char s[], int b) {
    
    int i, sign;

    sign = n;
    i = 0;

    do {
        int digit = (n < 0 ? -(n % b) : n % b); // b is for user specified bases
        s[i++] = digit + (digit < 10 ? '0' : 'a' - 10);
    } while ((n /= b) != 0 );
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s); 
}

void paddedItoa(int n, char s[], int p) {

    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = (n < 0 ? -(n % 10) : n % 10) + '0';
    } while ((n /= 10) != 0 );
    if (sign < 0) {
        s[i++] = '-';
    }
    while (i < p) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);

}

int main() {

    char s[100]; // modify if set integers/paddings extend beyond 100

itoa(123, s);
printf("ITOA for n = 123: %s\n", s);

itoa(-123, s);
printf("ITOA for n = -123: %s\n", s);

itoa(-2147483648, s);
printf("ITOA for n = -2147483648: %s\n", s);

itob(255, s, 16);
printf("ITOB for n = 255 and base 16: %s\n", s);

itob(-255, s, 16);
printf("ITOB for n = 255 and base 16: %s\n", s);

paddedItoa(255, s, 3);
printf("paddedITOA for n = 255 and pads 3: %s\n", s);

paddedItoa(-123456, s, 1);
printf("paddedITOA for n = -123456 and pads 1: %s\n", s);

paddedItoa(0, s, 21);
printf("paddedITOA for n = 0 and pads 21: %s\n", s);
    
return 0;
}