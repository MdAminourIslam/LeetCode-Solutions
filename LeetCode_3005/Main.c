int max(int a, int b) {
    return a > b ? a : b;
}
int maxFrequencyElements(int* nums, int numsSize) {
    int cnt[101] = {0};
    int mx = 0;
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]] += 1;
        mx = max(mx, cnt[nums[i]]);
    }
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum = (cnt[i] == mx ? sum + mx : sum);
    }
    return sum;
}