#include <stdio.h>

// register input lines into an array and replace vowels with hashtags

#define MAX 1000  

int myGetLine(char line[], int lim);
void replaceVowels(char line[]);

int main() {
 
    int c, i, len;
    char line[MAX];

    while ((len = myGetLine(line, MAX)) > 0) {
        replaceVowels(line);
        printf("%s", line);

    }
return 0;     
} 

int myGetLine(char line[], int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
return i;
}

void replaceVowels(char line[]) {

    int c, i;

    for (i = 0; line[i] != '\0'; ++i) {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
        line[i] = '#';
    }
}