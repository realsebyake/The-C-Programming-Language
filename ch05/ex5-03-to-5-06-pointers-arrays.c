#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0' // needed for getop

void myStrcat(char *s, char *t);
void myStrncpy(char *s, char *t, int n);
void myStrncat(char *s, char *t, int n);
void itoa(int n, char s[]);
void reverse(char *s);
int myStrend(char *s, char *t);
int myStrncmp(char *s, char *t, int n);
int myGetline(char *s, int lim);
int atoi(char s[]);
int strindex(char *s, char *t);
char s[20] = "hello";
char t[] = " world!";

int main() {

    //myStrcat(s, t);
    //myStrncpy(s, "hi", 2);
    //myStrncat(s, t, 3);
    //myGetline(s, 100);

    //printf("Strend 1: %d\n", myStrend("hello world", "world"));
    //printf("Strend 2: %d\n", myStrend("hello world", "hello"));
    //printf("Strend 3: %d\n", myStrend("hello", "hello"));

    //printf("Strncmp 1:%d\n", myStrncmp("hello", "hello", 5));
    //printf("Strncmp 2:%d\n", myStrncmp("hello", "world", 5));
    //printf("Strncmp 3:%d\n", myStrncmp("hello", "hello", 3));
    //printf("%d\n", strindex("hello world", "world"));
    //printf("%d\n", strindex("hello world", "xyz"));

    //itoa(123, s);
    //printf("%s\n", s);
    //itoa(-456, s);
    //printf("%s\n", s);

    printf("%s\n", s);

return 0;
}

void myStrcat(char *s, char *t) {

    while (*s)
        s++;
    while (*t)
        *s++ = *t++;
    *s = '\0';
}

int myStrend(char *s, char *t) {

    int lengthTotal = strlen(s) - strlen(t);
    if (lengthTotal < 0)
        return 0;
    s = s + lengthTotal;
    while (*s && *t && *s == *t) {
        s++;
        t++;
    }
    return *t == '\0';
}

void myStrncpy(char *s, char *t, int n) {

    while (n > 0 && *t != '\0') {
        *s = *t;
        t++;
        s++;
        n--;
    }
    *s = '\0';
}

void myStrncat(char *s, char *t, int n) {

    while (*s)
        s++;
    while (n > 0 && *t != '\0') {
        *s++ = *t++;
        n--;
    }
    *s = '\0';
}

int myStrncmp(char *s, char *t, int n) {

    while (n > 0 && *s != '\0' && *s == *t) {
        s++;
        t++;
        n--;
    }
return *s - *t;
}

// from this point onwards, its just pointer rewrites on functions in 5-6

int myGetline(char *s, int lim) {

    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

int atoi(char s[]) {

    int n, sign;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    n = 0;
    while (isdigit(*s)) {
        n = 10 * n + (*s - '0');
        s++;
    }
    return sign * n;
}

void reverse(char *s) {
    char *end = s;
    char temp;

    while (*end)
        end++;
    end--;

    while (s < end) {
        temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}

void itoa(int n, char *s) {

    int sign;
    char *start = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(start);
}

int strindex(char *s, char *t) {

    char *start = s;
    char *ps, *pt;

    while (*s != '\0') {
        ps = s;
        pt = t;
        while (*pt != '\0' && *ps == *pt) {
            ps++;
            pt++;
        }
        if (*pt == '\0')
            return s - start;
        s++;
    }
    return -1;
}

int getop(char *s) {

    int c;
    static int leftover = 0;

    while ((*s = c = (leftover ? leftover : getchar())) == ' ' || c == '\t')
        leftover = 0;
    leftover = 0;
    *(s+1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        *s++ = c;
    while (isdigit(*s++ = c = getchar()))
        ;
    if (*s == '.')
        s++;
    *s = '\0';
    if (c != EOF)
        leftover = c;

return NUMBER;
}

/* Exercise 5-3: Write a pointer version of the function strcat that we showed in chapter 2: strcat(s,t) copies the string t to the end of s */
/* Exercise 5-4: Write the function strend(s, t), which returns 1 if the  string t occurs at the end of the string s and zero otherwise */
/* Exercise 5-5: Write versions of the library functions strncpy, strncat, and strncmp, which operate on at the most the first n characters of their argument strings. For example. strncpy(s,t,n) copies at the most n characters of t to s. */
/* Exercise 5-6: Rewrite appropriate programs from earlier chapters and exercises with pointers instead of arrays indexing. Good posibilities include getline (chapters 1 and 4), atoi, itoa, and their variants (Chapter 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4). */
// test fish / s = test fish / t = fish
