#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    long long op = 0;
    int len = strlen(s);
    for (int i = shiftsSize - 1; i >= 0; i--) {
        op += shifts[i];
        int d = s[i] - 'a';
        d = (d + op) % 26;
        s[i] = d + 'a';
    }
    return s;
}
