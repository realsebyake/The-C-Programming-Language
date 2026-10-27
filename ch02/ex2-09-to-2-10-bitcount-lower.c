int main()  {

int x;
int c;

return 0;
}

int bitcount(unsigned x) { // Example provided by K&R

    int b;

    for (b = 0; x != 0; x >>= 1) 
        if (x & 01)
            b++;
    return b;

}

int bitcount2(unsigned x) { // Ex 2-9
    
    int c;

    for (c = 0; x != 0; x &= x - 1)
            c++;
    return c;
}

int assignLower(int c) {

   return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

}

/*

x = 1; 000001
x >>= 1 is short for x = x >> 1
x = 00000


0001001




*/