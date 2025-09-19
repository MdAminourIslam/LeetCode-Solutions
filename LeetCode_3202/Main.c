
int maximumLength(int* nums, int numsSize, int k) {
    int dp[k][k];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i] % k;
        for (int prev = 0; prev < k; prev++) {
            dp[prev][num] = dp[num][prev] + 1;
            if (dp[prev][num] > res) {
                res = dp[prev][num];
            }
        }
    }
    return res;
}