#include <stdio.h>

int htoi(char s[]) {

    int result = 0;
    int i = 0;

        while (s[i] != '\0') {
            char c = s[i];
            int value;
    
            if (c >= '0' && c <= '9') {
                value = c - '0';
            } else if (c >= 'A' && c <= 'F') {
                value = c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                value = c - 'a' + 10;
            } else {
                // Invalid character for hexadecimal
                break;
            }
    
            result = result * 16 + value;
            i++;
        }

return result;
}

int main() {
    char hex_string[] = "1A3F";
    int decimal_value = htoi(hex_string);
    printf("Decimal value: %d\n", decimal_value);
    return 0;
}