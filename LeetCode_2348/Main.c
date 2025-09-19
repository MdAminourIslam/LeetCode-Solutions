long long zeroFilledSubarray(int* nums, int numsSize) {
    long long cnt = 0, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            cnt++;
        } else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ans += cnt * (cnt + 1) / 2;
    return ans;
}
