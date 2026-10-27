// 1.9 Character Arrays

#include <stdio.h>

#define MAXLINE 1000

int myGetLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {

    int len; 
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;

    while ((len = myGetLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int myGetLine(char s[], int lim) {

    int c, i;

for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;

    // this statement is from ex. 1-16, remove if needed
if (i == lim - 1) {
    while ((c = getchar()) != EOF && c != '\n')
        ++i;
}

if (c == '\n') {
    s[i] = c;
    ++i;
}
s[i] = '\0';
return i;


    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {

    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

// Exercise 1-17    

void longerThan80() {

    int len;
    char line[MAXLINE];

    while ((len = myGetLine(line, MAXLINE)) > 0)
        if (len > 80) {
    printf("%s", line);
        }
}

// Exercise 1-18

void DeleteChars() {

    int len, i;
    char line[MAXLINE];

    while ((len = myGetLine(line, MAXLINE)) > 0) {
        i = len - 1;
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
            --i;
        line[i + 1] = '\0';
        if (i >= 0)
            printf("%s\n", line);
    }
}

// Exercise 1-19

void reverse(char s[], int len) {
    int i, j, temp;
    i = 0;
    j = len - 1;
    
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i; --j;   
    }
}

// P.S write myGetLine instead of getline as it was added as a function in the library after the book was released to avoid conflicts.