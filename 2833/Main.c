#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int abs(int n) {
    return (n < 0) ? -n : n;
}

int furthestDistanceFromOrigin(char* moves) {
    int mn = 0, mx = 0;
    
    for (int i = 0; moves[i] != '\0'; i++) {
        char ch = moves[i];
        if (ch == 'L') {
            mn = mn - 1;
            mx = mx - 1;
        } else if (ch == 'R') {
            mn = mn + 1;
            mx = mx + 1;
        } else {
            mn = mn - 1;
            mx = mx + 1;
        }
    }
    
    return max(abs(mn), abs(mx));
}
