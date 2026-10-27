#include <stdio.h>

  void escape(char s[], char t[]);
  void unescape(char s[], char t[]);

  int main() {                                                                                       
      char original[] = "hello\there\nbye";
      char escaped[50];
      char unescaped[50];                                                                            
   
      escape(escaped, original);                                                                     
      printf("escaped:   %s\n", escaped);
                                                                                                     
      unescape(unescaped, escaped);
      printf("unescaped: %s\n", unescaped);                                                          
                                                                                                     
      return 0;
  }    

void escape(char s[], char t[]) {

    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {

    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; i++)  {
        if (t[i] == '\\') {
            i++;
            switch (t[i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = t[i];
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}