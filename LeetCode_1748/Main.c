
int sumOfUnique(int* nums, int numsSize) {
    int cnt[101] = {0}; // 1 to 100

    for(int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    int sum = 0;
    for(int i = 1; i <= 100; i++) {
        sum = cnt[i] == 1 ? sum + i : sum;
    }
    return sum;
}
