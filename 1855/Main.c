#include <stdio.h>
#include <stdlib.h>

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, ans = 0;

    while (i < nums1Size) {
        while (j < nums2Size && nums2[j] >= nums1[i]) {
            j++;
        }

        if (j >= i + 1) {
            ans = fmax(ans, j - i - 1);
        }

        i++;
    }

    return ans;
}