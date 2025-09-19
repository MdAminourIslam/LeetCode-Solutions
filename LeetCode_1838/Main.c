

int main() {
    int nums[] = {1, 2, 4};
    int k = 5;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxFrequency(nums, size, k);
    printf("Max Frequency: %d\n", result);
    return 0;
}
