#include <stdio.h>

int maxDistance(int* colors, int n) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (colors[i] != colors[j]) {
                if (j - i > res) {
                    res = j - i;
                }
            }
        }
    }
    return res;
}