  #include <stdio.h>
  #include <ctype.h>
  
  void expand(char s1[], char s2[]);

  int main() {
      char s2[100];

      expand("a-z", s2);     printf("%s\n", s2);
      expand("a-b-c", s2);   printf("%s\n", s2);
      expand("a-z0-9", s2);  printf("%s\n", s2);
      expand("-a-z", s2);    printf("%s\n", s2);
      expand("a-z-", s2);    printf("%s\n", s2);

      return 0;
  }

  void expand(char s1[], char s2[]) {
      int i, j, k;
      i = j = k = 0;

      for (i = 0; s1[i] != '\0'; i++) {
          if (s1[i] == '-') {
              if (i > 0 && (isalpha(s1[i-1]) || isdigit(s1[i-1])) && (isalpha(s1[i+1]) || isdigit(s1[i+1]))) {
                  for (k = s1[i-1] + 1; k <= s1[i+1]; k++)
                      s2[j++] = k;
                  i++;
              } else {
                  s2[j++] = '-';
              }
          } else {
              s2[j++] = s1[i];
          }
      }
      s2[j] = '\0';
  }