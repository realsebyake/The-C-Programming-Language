// example found in book which is "used" by ex 2-4
void squeeze(char s1[], int c) {

    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (s1[i] != c)
            s1[j++] = s1[i];
    s1[j] = '\0';
    
}

// ex 2-4
void squeezeDelete(char s1[], char s2[]) {

    int i, j = 0, k;
    
    for (i = 0; s1[i] != '\0'; i++) {
        int match = 0;
            for (k = 0; s2[k] != '\0'; k++) {
                if (s1[i] == s2[k])
                    match = 1;
            }
            if (match == 0)
                s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

// ex 2-5
int any(char s1[], char s2[]) {
 
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
            for (j = 0; s2[j] != '\0'; j++) {
                if (s1[i] == s2[j])
                    return i;
            }
    }
return -1;
}

int main() {

int c;
char s1[] = "sauce";
char s2[] = "chest";

// squeeze(s1, c);
// squeezeDelete(s1, s2);
// any(s1, s2);

// printf("%s\n", s1);

return 0;
}