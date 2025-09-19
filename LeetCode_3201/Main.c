
int max(int x, int y) {
    return x > y ? x : y;
}

int maximumLength(int* nums, int numsSize) {
    int len = 0;
    int mod = 0;
    int odd = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x % 2 != mod) {
            len += 1;
            mod = x & 1;
        }
        odd += (x & 1);
    }

    int mx = max(len, odd);
    mx = max(mx, numsSize - odd);

    len = 0, mod = 1;
    
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x % 2 != mod) {
            len += 1;
            mod = x & 1;
        }
    }

    return max(mx, len);
}