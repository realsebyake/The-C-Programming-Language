#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n) { // example provided by K&R
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1; /* no match */
}

int binsearchCompact(int x, int v[], int n) { // Ex 3-2
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high + 1) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    return (x == v[low]) ? low : -1;
}

int main() {

    int v[100000];
    int i = 0;
    int x = 7;
    int n = sizeof(v) / sizeof(v[0]);

    for (i = 0; i < 100000; i++) {
        v[i] = i * 2;
    }

    clock_t start1 = clock();
    for (i = 0; i < 100000; i++) {
        binsearch(x, v, n);
    }
    clock_t end1 = clock();
    double elapsedTime1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    for (i = 0; i < 100000; i++)  {
        binsearchCompact(x, v, n);
    }
    clock_t end2 = clock();
    double elapsedTime2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Search result for normal binsearch: %d | runtime: %f\n", binsearch(x, v, n), elapsedTime1);
    printf("Search result for compacted binsearch: %d | runtime: %f\n", binsearchCompact(x, v, n), elapsedTime2);

return 0;
}