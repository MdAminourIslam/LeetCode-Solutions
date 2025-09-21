int evenNumberBitwiseORs(int* nums, int numsSize) {
    int answer = 0;
    for (int i = 0; i < numsSize; i++) {
        answer = (nums[i] & 1 ? answer : answer | nums[i]);
    }
    return answer;
}