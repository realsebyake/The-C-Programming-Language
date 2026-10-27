#include <stdio.h>

int main() {

int flag = 1;
int c, lim = 1000, i = 0;
char s[1000];

while (flag == 1) {
        c = getchar();
        if (i >= lim-1)
            flag = 0;
        if (c == '\n')
            flag = 0;
        if (c == EOF)
            flag = 0;
        if (flag == 1) {
            s[i] = c;
            ++i;
        }
        
}

return 0;
}