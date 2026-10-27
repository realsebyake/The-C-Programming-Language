#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {

    printf("ATOF is: %f\n", atof("123.45"));
    printf("ATOF is: %e\n", atof("123.5e-9"));
    printf("ATOF is: %f\n", atof("124.6e+6"));

return 0;
}

double atof(char s[]) {

    double val, power;
    int i, sign, exp, expsign;
    exp = 0;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp = 0; isdigit(s[i]); i++)
        exp = exp * 10 + (s[i] - '0');
    while (exp-- > 0)
        if (expsign < 0)
         val /= 10.0;
        else
         val *= 10.0;

    printf("exp: %d, expsign: %d\n", exp, expsign); // debug printf, dont mind it
    return sign * val / power;
}
