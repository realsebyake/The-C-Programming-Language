#include <stdio.h>
#include <string.h>

int itoa_r(int n, char s[], int i);
void reverse_r(char s[], int left, int right);
void reverse(char s[]);

int main() {

    char s[20];
    itoa_r(123, s, 0);
    printf("%s\n", s);
    itoa_r(-456, s, 0);
    printf("%s\n", s);

    char str[] = "hello";
    reverse(str);
    printf("%s\n", str);

}

int itoa_r(int n, char s[], int i) {

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        i = itoa_r(n / 10, s, i);
    s[i++] = n % 10  + '0';
    s[i] = '\0';
    return i;

}

void reverse_r(char s[], int left, int right) {
    
    int temp;

    if (left >= right)
        return;
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    
    reverse_r(s, left + 1, right - 1);
}

void reverse(char s[]) {
    reverse_r(s, 0, strlen(s) - 1);
}
