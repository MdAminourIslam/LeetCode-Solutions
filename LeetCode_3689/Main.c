
long long maxTotalValue(int* nums, int n, int k) {
    long long mx = 0, mn = 1000000000;
    for (int i = 0; i < n; i++) {
        if (nums[i] > mx) mx = nums[i];
        if (nums[i] < mn) mn = nums[i];
    }
    return (mx - mn) * k;
}